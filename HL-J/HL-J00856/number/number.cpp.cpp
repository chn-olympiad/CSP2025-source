#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <stdio.h>
using namespace std;

long long i=1,a[1000010],j=0,maxn=-1;
int main(){
    freopen("number.in",'r',stdin);
    freopen("number.out",'w',stdout);
    char s[1000010];
    while(s){
        if(s[i]<10&&s[i]>=0){
            j++;
            a[j]=s[i];
        }
    }
    for(int k=1;k<=j;k++){
        for(int t=1;t<=j;t++){
            if(a[t]>maxn){
                maxn=a[t];
                a[t]=-2;
            }
        }
        cout<<maxn;
        maxn=-1;
    }
    return 0;
}
