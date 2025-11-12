#include<bits/stdc++.h>
using namespace std;
int T,n,k,ans=0,sum[5];
bool bok[100010];
struct node{
    int a,b,c;
}x[300030];
bool cmp(node liu1,node liu2)
{
    return liu1.a>liu2.a;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&T);
    while(T--)
    {
        ans=0;
        scanf("%d",&n);
        k=n>>1;
        sum[1]=0,sum[2]=0,sum[3]=0;
        memset(bok,false,sizeof(bok));
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d",&x[i].a,&x[i+n].a,&x[i+n+n].a);
            int mina=min(x[i].a,min(x[i+n].a,x[i+n+n].a));
            ans+=mina;
            x[i].a-=mina,x[i+n].a-=mina,x[i+n+n].a-=mina;
            x[i].b=i;x[i+n].b=i;x[i+n+n].b=i;
            x[i].c=1;x[i+n].c=2;x[i+n+n].c=3;
        }
        sort(x+1,x+n+n+n+1,cmp);
        for(int i=1;i<=n+n+n;i++)
        {
            if(sum[x[i].c]>=k)continue;
            if(bok[x[i].b])continue;
            ans+=x[i].a;
            sum[x[i].c]=sum[x[i].c]+1;
            bok[x[i].b]=true;
        }
        printf("%d\n",ans);
    }
    return 0;
}
