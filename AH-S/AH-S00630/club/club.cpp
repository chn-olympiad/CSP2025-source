#include<bits/stdc++.h>
using namespace std;
int a[100000][3],n,club[3];
long long ans,maxx;
void dfs(int k)
{
    if(k>=n)
    {
        ans=max(ans,maxx);
        return;
    }
    for(int i=0;i<3;i++)
    {
        if(club[i]<n/2)
        {
            maxx+=a[k][i];
            club[i]+=1;
            dfs(k+1);
            club[i]-=1;
            maxx-=a[k][i];
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        n=0;
        scanf("%d",&n);
        ans=0;
        maxx=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
        }
        dfs(0);
        printf("%lld\n",ans);
    }
    return 0;
}
