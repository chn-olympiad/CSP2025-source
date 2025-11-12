//seat.cpp
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

int main(){
    
    int n , m , ne , me , e , f ;
    int i = m * n ;
    int h , j , p;
    string text;
    ifstream in("seat.in");
    while(getline(in,text)){
        istringstream(text) >> n >> m ;
    }
    i = m * n ;
    int a[i];
    while(getline(in,text)){
        istringstream(text) >> a[1,i] ;
    }
    f = a[1] ;
    for(h=1 ; h < i ; h++){
        if( a[h] < a[h+1] ){
            e = a[h] ;
            a[h] = a[h+1] ;
            a[h+1] = e ;
        }
    }
    for(j = 1 ; j < m ; j++){
        if(j%2 == 1){
            for(p = 1 ; p < n ; p++){

            }
        }else{
            for(p = 1 ; p < n ; p++){

            }
        }
    }

    ofstream out("seat.out");
    out << n << " " << m ;
    return 0;
}