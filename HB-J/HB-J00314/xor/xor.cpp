#include <bits/stdc++.h>
using namespace std;

int n,k,sum1=0,sum2=0;
int a[500010];

int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==0) sum1++;
        if(a[i]==1) sum2++;
    }
    if(k==0) cout<<sum1+sum2/2;
    if(k==1) cout<<sum2+sum1/2;
    return 0;
}
