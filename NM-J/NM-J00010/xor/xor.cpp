#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    long long k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        if(a[i]==k)
        {
            ans++;
        }
        for(int j=1;j<=i;j++)
        {
            int c=j;
            sum=0;
            while(c!=i)
            {
                sum+=a[c];
                c++;
            }
            if(sum==k)
            {
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
