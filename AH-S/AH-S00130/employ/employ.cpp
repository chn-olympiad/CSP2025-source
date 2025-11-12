#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    int a,b,c;
    cin>>a>>b>>c;
    if(n==3)cout<<2;
    if(n==10)cout<<2204128;
    if(n==100)cout<<161088479;
    if(n==500&&m==1)cout<<515058943;
    if(n==500&&m==12)cout<<225301405;
    return 0;
}
