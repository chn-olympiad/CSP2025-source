#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)>(b)?(b):(a))
const int MAX = 1e6+10;
const int INF = 1e6;
struct ST{int a,b,c;int maxn;}s[MAX];
int n,ans,cnt;
void dfs(int idx,int sum,int x,int y,int z)
{
    if(idx==n)
    {
        ans=max(ans,sum);
        cnt+=1;
        return;
    }
    for(int i=idx+1;i<=n;i++)
    {
        if(x<(n/2)) dfs(i,sum+s[i].a,x+1,y,z);
        if(y<(n/2)) dfs(i,sum+s[i].b,x,y+1,z);
        if(z<(n/2)) dfs(i,sum+s[i].c,x,y,z+1);
    }
}
bool cmp(ST a,ST b)
{
    return a.maxn<b.maxn;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);ans=0;
        cnt=0;
        for(int i=1;i<=n;i++)
        {
            int a,b,c;scanf("%d %d %d",&a,&b,&c);
            s[i].maxn=max(a,max(b,c));
            s[i].a=a;s[i].b=b,s[i].c=c;
        }
        sort(s+1,s+1+n,[](ST a,ST b)
        {
             if(a.a!=b.a) return a.a>b.a;
             else if(a.b!=b.b) return a.b>b.b;
             else if(a.c!=b.c) return a.c>b.c;
        });
        dfs(1,s[1].a,1,0,0);
        dfs(1,s[1].b,0,1,0);
        dfs(1,s[1].c,0,0,1);
        printf("%d\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
