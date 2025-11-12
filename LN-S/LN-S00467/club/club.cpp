#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100009][5];
int mx=0,n;
bool vis[100009];
int rl[5];
void dfs(int cnt,int s)
{
    if(cnt==n)
    {
        mx=max(mx,s);
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            for(int j=1;j<=3;j++)
            {
                if(rl[j]>=1)
                {
                    cnt++;
                    rl[j]--;
                    vis[i]=1;
                    s+=a[i][j];
                    dfs(cnt,s);
                    cnt--;
                    s-=a[i][j];
                    vis[i]=0;
                    rl[j]++;
                }
            }
        }
    }
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        memset(vis,0,sizeof(vis));
        mx=0;
        cin>>n;
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0||a[i][3]!=0){ok=0;}
        }
        if(ok==1)
        {
            int b[100009];
            for(int i=1;i<=n;i++)
            {
                b[i]=a[i][1];
            }
            sort(b+1,b+n+1);
            int ans=0;
            for(int i=n;i>=n/2;i--){ans+=b[i];}
            cout<<ans<<endl;
            continue;
        }
        rl[1]=n/2;
        rl[2]=n/2;
        rl[3]=n/2;
        dfs(0,0);
        cout<<mx<<endl;
    }
    return 0;
}
