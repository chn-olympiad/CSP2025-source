#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long sum[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(long long i=1,x;i<=n;i++)
    {
        cin>>x;
        sum[i]=sum[i-1]^x;
    }
    int i=0,j=0;
    while(j<n)
    {
        i++;
        if((sum[i]^sum[j])==k){
            ans++;
            j=i;
            i++;
        }
        if(i==n)
        {
            j++;
            i=j+1;
        }
    }
    cout<<ans;
    return 0;
}
