#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[510];
char s[510];
long long ans;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int dy=0;
    int dq;
    while(n--)
    {
        for(int i=1;i<=n;i++)
        {
            if(a[i]>=dy&&s[i]=='1') dq++;
            dy++;
        }

        if(dq==n) ans++;
    }
    cout<<ans%998244353+1;
    return 0;
}
