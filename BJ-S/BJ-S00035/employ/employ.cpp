#include <bits/stdc++.h>

using namespace std;
char a[1000];
int s[1000];
int p[1000];
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s[i]=a[i]-'0';
    }
    int tp;
    for(int i=1;i<=n;i++)
    {
        cin>>tp;
        p[tp]++;
    }
    int sum=n;
    long long ans=1;
    for(int i=1;i<=m;i++)
    {
        ans*=sum;
        ans%=998244353;
        sum--;
    }
    cout<<ans;
    return 0;
}
