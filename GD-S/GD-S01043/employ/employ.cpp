#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
long long n,m,a[maxn],b[maxn],d[maxn],ans;
void dfs(int x)
{
    if(x>n)
    {
        int s=0,k=0;
        for(int i=1;i<=n;i++)
        {
            if(!a[i])k++;
            else
            {
                if(k>=d[i])k++;
                else s++;
            }
        }
        if(s>=m)ans++;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(d[i]==-1)
        {
            d[i]=b[x];
            dfs(x+1);
            d[i]=-1;
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
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;
        a[i]=c-'0';
        d[i]=-1;
    }
    for(int i=1;i<=n;i++)cin>>b[i];
    dfs(1);
    cout<<ans;
}