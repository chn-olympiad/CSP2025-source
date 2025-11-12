#include<bits/stdc++.h>
#define ll  unsigned long long
using namespace std;
ll n,k,a;
ll cnt=0;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
    {
        cin>>a;
        if(a==k) cnt++;
    }
    cout<<cnt;
    return 0;
}
