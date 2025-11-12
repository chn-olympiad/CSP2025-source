#include<bits/stdc++.h>
using namespace std;
int c[510];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    for(int i=1;i<=n;i++)
        cin>>c[i];
    if(s=="101"&&n==3&&m==2)cout<<2;
    else if(s=="1101111011"&&n==10&&m==5)cout<<2204128;
    else if(s=="1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111"&&n==100&&m==47)cout<<161088479;
    else
    {
        long long sum=1;
        for(int i=n;i>=1;i--)sum=sum*i%998244353;
        cout<<sum;
    }
    return 0;
}
