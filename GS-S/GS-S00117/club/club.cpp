#include <iostream>
#include <cstdio>
#include <cstring>
#define ll unsigned long long

using namespace std;

const int maxn = 100005;

ll a[maxn][5],dp[maxn],c[5];
ll man;
int n;

void DFS(int step ,int c1,int c2,int c3,ll ans)
{
    if(step>n)
    {
        man=max(man,ans);
        return;
    }
    if((c1+1)*2<=n) DFS(step+1,c1+1,c2,c3,ans+a[step][1]);
    if((c2+1)*2<=n) DFS(step+1,c1,c2+1,c3,ans+a[step][2]);
    if((c3+1)*2<=n) DFS(step+1,c1,c2,c3+1,ans+a[step][3]);

}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
   int t;
   scanf("%d",&t);
   while(t--)
   {
       man=0;
       scanf("%d",&n);
       memset(a,0,sizeof(a));
       //memset(dp,0,sizeof(dp));
       //c[1]=c[2]=c[3]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i][1]);
            scanf("%d",&a[i][2]);
            scanf("%d",&a[i][3]);

        }
        DFS(1,0,0,0,0);
        cout<<man;

   }
    return 0;

}
