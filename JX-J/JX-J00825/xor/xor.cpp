#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500010],sum=0;
signed main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)sum++;
        for(int j=i+1;j<=n;j++)
        {
            if(a[i]==a[j])sum++;
        }
    }
    cout<<sum;
    return 0;
}