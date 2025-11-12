#include<iostream>
#include<algorithm>
#define L long long
using namespace std;
constexpr int Mn=1e6+3e5,Mn2=1e4+100;
struct I
{
    int X,Y,Z;
    bool operator < (const I& k)const
    {
        return Z<k.Z;
    }
}c1[Mn],c[Mn];
bool r[Mn],r2[Mn2];
int n,m,m2,k,q[Mn2],K[16],x;
L y,g;
int F(int l)
{
    if(q[l]==l)return l;
    return q[l]=F(q[l]);
}
void H(int j,int h)
{
    j=F(j);
    h=F(h);
    if(j==h)return;
    q[j]=h;
}
void Kruskal_1()
{//   yong      c1     jin xing ji suan.
    int i,j,h;
    for(i=1;i<=n;i++)q[i]=i;
    for(i=1;i<=m;i++)
    {
        j=F(c1[i].X);
        h=F(c1[i].Y);
        if(j==h)continue;
        H(j,h);
        r[i]=1;
        y+=c1[i].Z;
        x--;
        if(!x)break;
    }
}
void Kruskal()
{// yong    c       jin xing ji suan.
    int i,j,h;
    for(i=1;i<=n+k;i++)q[i]=i;
    for(i=1;i<=m2;i++)
    {
        j=c[i].X;
        h=c[i].Y;
        if(!r2[j])continue;
        if(!r2[h])continue;
        j=F(j);
        h=F(h);
        if(j==h)continue;
        H(j,h);
        g+=c[i].Z;
        x--;
        if(!x)break;
    }
    if(!x)y=min(y,g);
}
int main()
{//       Inportant
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j,h;
    cin>>n>>m>>k;
    for(i=1;i<=m;i++)cin>>c1[i].X>>c1[i].Y>>c1[i].Z;// zhu yi shi   c1  .
    sort(c1+1,c1+m+1);
    x=n-1;
    Kruskal_1();
    for(i=1;i<=m;i++)if(r[i])c[++m2]=c1[i];
    for(i=0;i<k;i++)
    {
        cin>>K[i];
        for(j=1;j<=n;j++)
        {
            m2++;
            c[m2].X=n+i+1;   // yao jia 1 .
            c[m2].Y=j;
            cin>>c[m2].Z;
        }
    }
    sort(c+1,c+m2+1);
    for(i=1;i<=n;i++)r2[i]=1;
    for(i=0;i<(1<<k);i++)
    {
        for(j=1;j<=k;j++)r2[n+j]=0;
        g=0;
        x=n-1;
        for(j=0;j<k;j++)if((i>>j)&1)
        {
            x++;
            g+=K[j];
            r2[n+j+1]=1;
        }
        Kruskal();
    }
    cout<<y;
    return 0;
}
