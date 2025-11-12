#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505;
const ll mod=998244353;
ll n,m,c[maxn],cnt,p,ans=1;
string s;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m,p=n;
    cin>>s;
    for(int i=0;i<n;i++) cnt+=(int)(s[i]-'0');
    for(int i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==0) p--;
    }
    for(int i=1;i<=n;i++)
    if(cnt==n)
    {
        if(p<m) cout<<0;
        else
        {
            for(int i=2;i<=p;i++) ans=ans*i%mod;
            cout<<ans;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
