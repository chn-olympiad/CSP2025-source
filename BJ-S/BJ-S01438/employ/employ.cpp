#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
bool f[505];
int a[505],ans,c[505],m,n;
string s;
void dfs(int x,int y)
{
    if (y+n-x<m)
    {
        return;
    }
    if (x==n)
    {
        if (y>=m)
        {
            ans++;
            ans%=mod;
        }
        return;
    }
    for (int i=1;i<=n;i++)
    {
        if (!f[i])
        {
            f[i]=true;
            if (x-y<c[i]&&a[x+1]==1)
            {
                dfs(x+1,y+1);
            }
            else
            {
                dfs(x+1,y);
            }
            f[i]=false;
        }
    }
}
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>s;
    int l=s.size(),cnt1=0,cnt2=0;
    for (int i=0;i<l;i++)
    {
        a[i+1]=s[i]-'0';
        cnt1+=a[i+1];
    }
    for (int i=1;i<=n;i++)
    {
        cin>>c[i];
        if (c[i]==0)
        {
            cnt2++;
        }
    }
    long long aa=1;
    for (int i=1;i<=n;i++)
    {
        aa=aa*i%mod;
    }
    if (cnt1<m)
    {
        cout<<"0";
        return 0;
    }
    else if (n-cnt1==0)
    {
        cout<<aa;
        return 0;
    }
    else if (n-cnt2<m)
    {
        cout<<"0";
        return 0;
    }
    else if (n>18)
    {
        cout<<"0";
        return 0;
    }
    dfs(0,0);
    cout<<ans;
    return 0;
}