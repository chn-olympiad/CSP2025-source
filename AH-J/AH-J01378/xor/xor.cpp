#include<bits/stdc++.h>
using namespace std;
int n,k,cnt,posa,posb;
long long a[500005],s[500005];
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if((s[i]^s[j-1])==k&&(i<posa||j>posb))
            {
                posa=j;
                posb=i;
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}
