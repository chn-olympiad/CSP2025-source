#include<bits/stdc++.h>
using namespace std;
int s[100000000];
int f[10000000];
int h[100000000];
int a=0,m=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    for(int i=0;i<100000000;i++){

    }
    while(s[a]!=0){
        if(s[a]!='a-z')f[a]=s[a];
        a++;

    }
    for(int i=0;i<a;i++){
        if(f[i]<f[i+1]){
            m=f[i];
            f[i]=f[i+1];
            f[i+1]=m;
        }

    }
    cout<<f;
    return 0;
}
