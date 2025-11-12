#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
using namespace std;
string s;
long long a[1000005];
int main(){
    preopen("number.in","r",stdin);
    preopen("number.out","w",stdout);
    cin>>s;
    int n=0;
    for(int i=1;i<=s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            n++;
            a[n]=s[i];
        }
    }
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        cout<<a[i];
    }


return 0;
}
