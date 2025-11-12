#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int a[21];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    char ch;
    while(1){
        ch=getchar();
        if(ch=='\n')break;
        if(ch>='0'&&ch<='9')a[ch-'0']++;
    }
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++){
            printf("%d",i);
        }
    }
    printf("\n");
    return 0;
}