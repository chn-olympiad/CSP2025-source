#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=998244353;
int n,m,jc[1000]={1},p,nn;
string aaa;
int fpow(int a,int k)
{
    int ans=1;
    while(k)
    {
        if(k&1)ans=ans*a%MOD;
        a=a*a%MOD;
        k>>=1;
    } 
    return ans;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    nn=n;
    cin>>aaa;
    for(int i=1;i<=n;i++)
    {
        cin>>p;
        if(!p)nn--;
    }
    jc[nn-m]=1;
    for(int i=nn-m+1;i<=nn;i++)
    {
        jc[i]=jc[i-1]*i%MOD;
    }
    cout<<jc[nn];
    //cout<<jc[n]*fpow(jc[n-m],MOD-2)%MOD;
    return 0;
}