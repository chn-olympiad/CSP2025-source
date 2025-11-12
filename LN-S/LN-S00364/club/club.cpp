#include <bits/stdc++.h>
using namespace std;
const int maxn=100012;
int b[maxn][4],n,ans,store[maxn];
int j[4],a[maxn][4],cnt=1;
void dfs(int step)
{
    if(step==n+1)
    {
       store[cnt]=ans;
       cnt++;
       return;
    }
    for(int i=1;i<=3;i++)
    {
        if(j[i]<n/2)
        {
            ans+=a[step][i];
            j[i]++;
            dfs(step+1);
            ans-=a[step][i];
            j[i]--;
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out,"w",stdout);
    int tt;
    cin>>tt;
    for(int z=1;z<=tt;z++)
    { cin>>n;
        for(int i=1;i<=n;i++)
            b[i][1]=b[i][2]=b[i][3]=0;
            memset(j,0,sizeof(j));
            memset(store,0,sizeof(store));
            cnt=1;
        for(int i=1;i<=n;i++)
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            dfs(1);
            int anss=0;
            for(int i=1;i<=cnt;i++)
                anss=max(anss,store[i]);
            cout<<anss<<endl;
    }
    return 0;
}
