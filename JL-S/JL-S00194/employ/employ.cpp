#include <bits/stdc++.h>
using namespace std;
int n,m;
long long fact[505];
const int mod=998244353;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    fact[1]=1;
    for(int i=2;i<=500;i++)
    {
        fact[i]=fact[i-1]*i%mod;
        //cout<<fact[i]<<endl;
    }
    cin>>n>>m;
    cout<<fact[n]<<endl;
    //cout<<0;
    return 0;
}
