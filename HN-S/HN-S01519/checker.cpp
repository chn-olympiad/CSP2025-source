#include<bits/stdc++.h>
using namespace std;
int nextchar(FILE *F,int &S,int &L){
    S=L=0;int c;
    while((c=fgetc(F))<=32||c>127)
        if(c==' ')S++;
        else if(c=='\n'){S=0;L++;}
        else if(c==EOF){S=L=0;break;}
    return c;
}
FILE *A,*B;
int a,b,c,d,e,f;
int main(int argc,char *argv[]){
    A=fopen(argv[2],"r");
    B=fopen(argv[3],"r");
    while(true){
        a=nextchar(A,b,c);
        d=nextchar(B,e,f);
        if(a!=d)return 1;
        if(b!=e)return 2;
        if(c!=f)return 3;
        if(a==EOF)return 0;
    }
}