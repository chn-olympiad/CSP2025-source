#include <bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[100005],s[100005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    s[1]=a[1];
    for(int i=2;i<=n;i++)
        s[i]=(a[i]^s[i-1]);
    for(int i=1;i<=n;)
    {
        for(int j=i;j<=n;j++)
        {
            if((s[j]^s[i-1])==k)
            {
                ans++;
                i=j+1;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
