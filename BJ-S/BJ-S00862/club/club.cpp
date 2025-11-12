#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N][10];
int b[10];
int n;
int sum,maxn;
void dfs(int step)
{
    if(step>n)
    {
        maxn=max(maxn,sum);
        return;
    }
    for(int i=1;i<=3;i++)
    {
        if(b[i]+1>(n/2)) continue;
        b[i]++;
        sum+=a[step][i];
        dfs(step+1);
        b[i]--;
        sum-=a[step][i];
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
        cin>>n;
        maxn=0;
        sum=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=3;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        dfs(1);
        printf("%d\n",maxn);
    }

    return 0;
}
