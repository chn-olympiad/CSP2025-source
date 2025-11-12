#include <bits/stdc++.h>
using namespace std;
#define int long long
struct Node{int mst,lst,d;}wt[100005];
struct Nd{int s,x;};
int t,n,sz,a[100005][5],ans,nt[5];
bool comp(Nd a,Nd b){return a.s>b.s;}
bool cmp(Node a,Node b){return a.d>b.d;}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%lld",&t);
    while (t--)
    {
        nt[1]=nt[2]=nt[3]=ans=0;
        scanf("%lld",&n),sz=n/2;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld",&a[i][1],&a[i][2],&a[i][3]);
            Nd num[5];
            for (int j=1;j<=3;j++) num[j]={a[i][j],j};
            sort(num+1,num+4,comp),ans+=num[2].s;
            wt[i]={num[1].x,num[2].x,num[1].s-num[2].s};
        }
        sort(wt+1,wt+n+1,cmp);
        for (int i=1;i<=n;i++)
        {
            if (nt[wt[i].mst]>=sz) nt[wt[i].lst]++;
            else nt[wt[i].mst]++,ans+=wt[i].d;
        }
        printf("%lld\n",ans);
    }
    return 0;
}