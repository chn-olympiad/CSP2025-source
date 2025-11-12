#include <bits/stdc++.h>
using namespace std;
int t,n,x,y,z,a[110000][11],cnt[11];
long long ans;
void dfs(int i,long long sum)
{
    if(i>n)
    {
        ans=max(ans,sum);
        return;
    }
    for(int j=1;j<=3;j++)
    {
        if(cnt[j]+1<=n/2)
        {
            cnt[j]++;
            dfs(i+1,sum+a[i][j]);
            cnt[j]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ans=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            a[i][1]=x;
            a[i][2]=y;
            a[i][3]=z;
        }
        dfs(1,0);
        cout<<ans<<endl;
    }
    return 0;
}
