#include<bits/stdc++.h>
using namespace std;
long long x,a[500005],b[500005];
int n,l=0,ans;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> x;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        b[i]=b[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=l;j--)
        {
            int t=b[i]^b[j];
            if(t==x)
            {
                ans++;
                l=i;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}
