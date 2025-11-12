#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,b,c;
}s[100010];
int n,m,ans;
void dfs(int step,int sa,int sb,int sc,int ca,int cb,int cc)
{
    if(step>n)
    {
        ans=max(ans,sa+sb+sc);
        return;
    }
    if(ca<m)dfs(step+1,sa+s[step].a,sb,sc,ca+1,cb,cc);
    if(cb<m)dfs(step+1,sa,sb+s[step].b,sc,ca,cb+1,cc);
    if(cc<m)dfs(step+1,sa,sb,sc+s[step].c,ca,cb,cc+1);
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d %d %d",&s[i].a,&s[i].b,&s[i].c);
        m=n/2,ans=0;
        dfs(1,0,0,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
