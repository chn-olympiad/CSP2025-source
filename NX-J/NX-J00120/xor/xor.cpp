#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    int nu0=0,nu1=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0) nu0++;
        else nu1++;
    }
    if(k==1)
    {
        cout<<nu1;
    }
    else
    {
        cout<<nu0;
    }
    return 0;
}
