#include<iostream>
#include<bits/stdc++.h>
using namespace std;
char s[1000000],ans[1000000];
long long a[100000],l;

int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;

    l=sizeof(s);
    for(int i=0;i<l;i++){
        if(int(s[i])<=9 && int(s[i])>=0) a[i]=int(s[i]);
    }
    sort(a+l,a);
    for(int i=0;i<l;i++){
        cout<<a[i];
    }
    return 0;
}
