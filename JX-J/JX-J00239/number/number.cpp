#include<iostream>
#include<string>
#include<bits/stdc++.h>
using numespace std:
int main(){
    freopen("number.in","r",stdin);
    freopen("number.ans","w",stdout);
    char n;
    int j=0;
    cin<<n;
    int a[10000]{0};
    for(int i=0;i<strlen(n);i++){
        if((int(n[i])>=97)&&(int(n[i])<=122)){
                continue;
        }else{
            n[i]=a[j];
            j++;
        }
    }
    int sum=0;
    for(int i=0;i<size(a);i++){
		sum=a[i];
		a[i]=a[i+1];
        a[i+1]=sum;
    }
    for(int i=0;i<size(a);i++){
        cout<<a[i];
    }
    return 0;
}
