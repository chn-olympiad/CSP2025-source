#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=101000;
const int maxm=1010000;
struct edge
{
    int from,to,next;
    ll len;
    friend bool operator <(edge a,edge b)
    {
        return a.len<b.len;
    }
}s[2*maxm],a[2*maxm],b[2*maxm];
/*int h[maxn],numptr;
void addedge(int x,int y,int z)
{
    s[numptr].to=y;
    s[numptr].len=z;
    s[numptr].next=h[x];
    h[x]=numptr++;
}*/
int fa[maxn],calc[maxn];
ll c[maxn];
int getroot(int x)
{
    if(fa[x]>0)return fa[x]=getroot(fa[x]);
    return x;
}
void un(int x,int y)
{
    x=getroot(x);
    y=getroot(y);
    if(x==y)return;
    if(fa[x]>fa[y])swap(x,y);
    fa[x]+=fa[y];
    fa[y]=x;
}
int in[maxn],tail;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(fa,-1,sizeof(fa));
    int n,m,i,j,k,l,r,len,p=0,tmp=0;
    ll sum=0,res,tag=0;
    scanf("%d%d%d",&n,&m,&k);
    for(i=1;i<=m;i++)scanf("%d%d%lld",&s[i].from,&s[i].to,&s[i].len);
    tail=m+1;
    for(i=1;i<=k;i++)
    {
        scanf("%lld",&c[i]);
        for(j=1;j<=n;j++)
        {
            scanf("%lld",&b[j].len);
            b[j].from=n+i;
            b[j].to=j;
            if(b[j].len==0)tmp=b[j].to;
        }
        for(j=1;j<=n;j++)
        {
            if(j==tmp)continue;
            s[tail].from=tmp;
            s[tail].to=b[j].to;
            s[tail].len=b[j].len;
            tail++;
        }
    }
    sort(s+1,s+tail);
    for(i=1;i<tail;i++)
    {
        if(getroot(s[i].from)==getroot(s[i].to))continue;
        un(s[i].from,s[i].to);
        //[tail++]=s[i];
        sum+=s[i].len;
    }
    printf("%lld\n",sum);
    return 0;
}
