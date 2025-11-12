#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
const int K=1e5+5;
const int SK=10+5;
struct node
{
    int x,y,z;
};
node e[M],ee[N];
int tot;
vector<node> v;
bool cmp(node aa,node bb)
{
    return aa.z<bb.z;
}
int fa[K],c[SK],a[SK][N];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&c[i]);
        for(int j=1;j<=n;j++)scanf("%d",&a[i][j]);
    }
    sort(e+1,e+1+m,cmp);
    for(int i=1;i<=n;i++)fa[i]=i;
    int fx,fy,ex=0;
    for(int i=1;i<=m;i++)
    {
        fx=find(e[i].x);
        fy=find(e[i].y);
        if(fx==fy)continue;
        fa[fx]=fy;
        ex++;
        ee[++tot]=e[i];
        if(ex==n-1)break;
    }
    long long ans=1e18,w;
    int qwq,hv;
    for(int i=0;i<(1<<k);i++)
    {
        w=0;
        qwq=hv=0;
        v.clear();
        for(int j=1;j<n;j++)v.push_back(ee[j]);
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j))
            {
                qwq++;
                w+=1ll*c[j];
                for(int h=1;h<=n;h++)v.push_back((node){n+qwq,h,a[j][h]});
            }
        }
        sort(v.begin(),v.end(),cmp);
        for(int j=1;j<=n+qwq;j++)fa[j]=j;
        for(int j=0;j<v.size();j++)
        {
            fx=find(v[j].x);
            fy=find(v[j].y);
            if(fx==fy)continue;
            fa[fx]=fy;
            hv++;
            w+=1ll*v[j].z;
            if(hv==n+qwq-1)break;
        }
        ans=min(ans,w);
    }
    cout<<ans<<endl;
    return 0;
}
