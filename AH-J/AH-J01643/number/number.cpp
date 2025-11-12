#include<iostream>
#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    long long l=s.length(),cnt=1;
    for(long long i=0;i<l;i++){
        if(s[i]>='0' && s[i]<='9')
            a[cnt]=s[i]-'0',cnt++;
    }
    cnt--;
    sort(a+1,a+1+cnt,cmp);
    for(long long i=1;i<=cnt;i++)printf("%d",a[i]);
    return 0;
}
