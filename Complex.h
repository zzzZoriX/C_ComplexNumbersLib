#ifndef COMPLEX_H
#define COMPLEX_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Complex {
    float real_part;
    int imaginary_part;
    char imag_part_sign;
} Complex;

Complex
Create_complex(float real_part, int imag_part){
    Complex new_complex;

    new_complex.real_part = real_part;
    new_complex.imaginary_part = imag_part;
    
    new_complex.imag_part_sign = imag_part >= 0 ? '+' : '-';

    return new_complex;
}


Complex
Sum_complex(Complex first, Complex second){
    Complex sum_result;
    
    sum_result.real_part = first.real_part + second.real_part;
    sum_result.imaginary_part = first.imaginary_part + second.imaginary_part;
    sum_result.imag_part_sign = sum_result.imaginary_part >= 0 ? '+' : '-';

    return sum_result;
}

Complex
Subtraction_complex(Complex first, Complex second){
    Complex sub_result;

    sub_result.real_part = first.real_part - second.imaginary_part;
    sub_result.imaginary_part = first.imaginary_part - second.imaginary_part;
    sub_result.imag_part_sign = sub_result.imaginary_part >= 0 ? '+' : '-';
    
    return sub_result;
}

Complex
Multiply_complex(Complex first, Complex second){
    Complex multi_result;

    multi_result.real_part = ((first.real_part * second.real_part) - (first.imaginary_part * second.imaginary_part));
    multi_result.imaginary_part = ((first.real_part * second.imaginary_part) + (first.imaginary_part * second.real_part));
    multi_result.imag_part_sign = multi_result.imaginary_part >= 0 ? '+' : '-';

    return multi_result;
}

Complex
Divide_complex(Complex first, Complex second){
    Complex div_result;

    div_result.real_part = ((first.real_part * second.real_part) + (first.imaginary_part * second.imaginary_part)) / (second.real_part * second.real_part + second.imaginary_part * second.imaginary_part);
    div_result.imaginary_part = ((first.imaginary_part * second.real_part) - (first.real_part * second.imaginary_part)) / (second.real_part * second.real_part + second.imaginary_part * second.imaginary_part);
    div_result.imag_part_sign = div_result.imaginary_part >= 0 ? '+' : '-';

    return div_result;
}


void
Print_complex(Complex number){
    printf("%f %c %di\n", number.real_part, number.imag_part_sign, number.imaginary_part * (number.imaginary_part >= 0 ? 1 : -1));
}

#endif