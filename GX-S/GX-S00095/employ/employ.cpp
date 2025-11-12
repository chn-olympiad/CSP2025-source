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
    #if 0
    fi = fopen("club.in", "r");
    fo = fopen("club.out", "w");
    #else
    fi=stdin;
    fo=stdout;
    #endif
    cout << inputi();
}
