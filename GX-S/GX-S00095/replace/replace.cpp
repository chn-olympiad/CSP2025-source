#include <bits/stdc++.h>
using namespace std;

FILE *fi,*fo;


int inputi(){
    int res=0,ch;
    ch=fgetc(fi);
    while(ch>='0'&&ch<='9'){
        res*=10;
        res+=ch-'0';
        ch=fgetc(fi);
    }
    return res;
}

int main(){
    #if 1
    fi = fopen("replace.in", "r");
    fo = fopen("replace.out", "w");
    #else
    fi=stdin;
    fo=stdout;
    #endif
    int n=inputi(),k=inputi();
    for(int i=0;i<k;i++){
        printf("0\n");
    }
}
