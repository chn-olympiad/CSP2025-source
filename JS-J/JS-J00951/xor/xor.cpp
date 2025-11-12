#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500010];
long long ans[500010];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++)
    {
        ans[i]=ans[i-1];
        int j=i;
        long long f=0;
        while (j>=1 && (f^a[j])!=k)
        {
            f=f^a[j];
            j--;
        }
        if (j>=1)
        {
            ans[i]=max(ans[i],ans[j-1]+1);
        }
    }
    cout<<ans[n];
    return 0;
}
