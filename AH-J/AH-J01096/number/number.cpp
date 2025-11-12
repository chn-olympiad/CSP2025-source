#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100001],f=0;
char b[100001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    scanf("%s",b);
    int t=strlen(b);
    for(int i=0;i<t;i++){
        if(b[i]>='0'&&b[i]<='9'){
            f++;
            a[f]=b[i]-'0';
        }
    }
    for(int i=1;i<f;i++){
        for(int j=i+1;j<=f;j++){
            if(a[i]<a[j])swap(a[i],a[j]);
        }
    }
    for(int i=1;i<=f;i++){
        cout<<a[i];
    }
    return 0;
}
