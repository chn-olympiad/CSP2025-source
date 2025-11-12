#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[5003],n,k;
void try5()
{
    cout<<n;
}
void try25()
{
    ll s0=0,s1=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==1)
        {
            s1++;
        }
        if(a[i]==0)
        {
            s0++;
        }
    }
    cout<<min(s1,s0);
}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(k==0)
    {
        try5();
        return 0;
    }
    if(k<=1)
    {
        try25();
        return 0;
    }
}
