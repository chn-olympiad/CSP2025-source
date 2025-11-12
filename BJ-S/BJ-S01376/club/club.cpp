#include<bits/stdc++.h>
using namespace std;
int u;
int n;
int a[100005][5];
int t[5];
long long ans;
int dfs(int x,int num,int res)
{
    if(x>n) return 0;
    int u=res;
    t[num]++;
    u+=a[num][x];
    int tmp=0;
    for(int i=1;i<=3;i++)
    {
        if(t[i]<(n/2))
        {
            int tpx=dfs(x+1,i,res);
            tmp=max(tmp,tpx);
        }
    }
    t[num]--;
    return u+tmp;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>u;
    while(u--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        bool f=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                cin>>a[j][i];
                if(j!=1&&a[j][i]) f=0;
            }
        }
        if(f)
        {
            sort(a[1]+1,a[1]+1+n);
            int ansans=0;
            for(int i=n;i>n/2;i--) ansans+=a[1][i];
            cout<<ansans<<endl;
            continue;
        }
        memset(t,0,sizeof(t));
        int ans1=dfs(1,1,0),ans2=dfs(1,2,0),ans3=dfs(1,3,0);
        ans=max(ans1,max(ans2,ans3));
        cout<<ans<<endl;
    }
    return 0;
}
//多给点分吧T_T
