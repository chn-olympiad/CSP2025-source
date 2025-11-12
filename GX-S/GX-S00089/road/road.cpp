#include<bits/stdc++.h>
using namespace std;
const int N=1e5+20,M=1e7+20;
int n,m,k,cnt,c[12],p[N];
typedef unsigned long long ull;
ull ans=0x3f3f3f3f3f3f3f3f;
struct Edge
{
    int a,b,w,cz;
    bool operator<(const Edge& a)const
    {
        return w<a.w;
    }
}edge[M],edge1[M];
int fi(int x)
{
    if(p[x]!=x)p[x]=fi(p[x]);
    return p[x];
}
int kus(int len)
{
    int sum=0;
    bool flag[12];
    memset(flag,0,sizeof flag);
    for(int i=1;i<=n;i++)p[i]=i;
    for(int i=0;i<len;i++)
    {
        int x=fi(edge1[i].a),y=fi(edge1[i].b);
        if(x!=y)
        {
            p[x]=y;
            sum+=edge1[i].w;
            int st=edge1[i].cz;
            if(st>0&&flag[st]==0)
            {
                sum+=c[st];
                flag[st]=1;
            }
        }
    }
    return sum;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        edge[cnt].a=x,edge[cnt].b=y,edge[cnt].w=z,edge[cnt].cz=0;
        cnt++;
    }
    sort(edge,edge+cnt);
    for(int j=0;j<cnt;j++)
            edge1[j]=edge[j];
    ans=kus(cnt);

    for(int i=1;i<=k;i++)
    {

        int len=cnt,h[N];
        scanf("%d",&c[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&h[i]);

        memset(edge1,0,sizeof edge1);
        for(int j=0;j<len;j++)
            edge1[j]=edge[j];

        for(int j=1;j<=n;j++)
        {
            for(int k=j+1;k<=n;k++)
            {
                edge1[len].a=j,edge1[len].b=k,edge1[len].w=h[j]+h[k],edge1[len].cz=i;
                len++;
            }

        }
        sort(edge1,edge1+len);
        ull x=kus(len);
        if(x<ans)
        {
            ans=x;
            for(int j=0;j<len;j++)
                edge[j]=edge[j];
            cnt=len;
        }
    }
    cout<<ans<<endl;
    return 0;
}
