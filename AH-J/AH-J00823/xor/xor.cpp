#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[1000005],x,s;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    for(ll i=1;i<=n;i++)
    {
        x=x^a[i];
        if(x>k*2) x=0;
        if(x==k)
        {
            x=0;
            s++;
        }
    }
    cout<<s;
    return 0;
}
