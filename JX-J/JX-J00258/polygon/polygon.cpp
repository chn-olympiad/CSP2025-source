#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int n,s[5005];
    cin>>n;
    for(int i=0;i<n;i++)cin>>s[i];
    int a=s[0];
    int b=s[1];
    int c=s[2];
    if(a+b>c||a+c>b||b+c>a)cout<<1;
    else cout<<0;
    return 0;
}
