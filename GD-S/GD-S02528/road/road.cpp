#include<cstdio>
#include<iostream>
using namespace std;
#define LL long long
const int N=1e4+10,M=2e6+10;
int n,m,p,a[11][N],b1[32][N*10][3],b2[32][N*10][3],l1[32],l2[32];
int b[M][3],tmp[M][3],tot1,c[M][3],d[M][3],tot;
int fa[N*2];
LL anss;
void qsort(int l,int r)
{
    int i=l,j=r,mid=b[(l+r)/2][0];
    while(i<=j)
    {
        while(b[i][0]<mid) i++;
        while(b[j][0]>mid) j--;
        if(i<=j)
        {
            swap(b[i][0],b[j][0]);
            swap(b[i][1],b[j][1]);
            swap(b[i++][2],b[j--][2]);
        }
    }
    if(i<r) qsort(i,r);
    if(l<j) qsort(l,j);
}
void qsort1(int x,int l,int r)
{
    int i=l,j=r,mid=b1[x][(l+r)/2][0];
    while(i<=j)
    {
        while(b1[x][i][0]<mid) i++;
        while(b1[x][j][0]>mid) j--;
        if(i<=j)
        {
            swap(b1[x][i][0],b1[x][j][0]);
            swap(b1[x][i][1],b1[x][j][1]);
            swap(b1[x][i++][2],b1[x][j--][2]);
        }
    }
    if(i<r) qsort1(x,i,r);
    if(l<j) qsort1(x,l,j);
}
void qsort2(int x,int l,int r)
{
    int i=l,j=r,mid=b2[x][(l+r)/2][0];
    while(i<=j)
    {
        while(b2[x][i][0]<mid) i++;
        while(b2[x][j][0]>mid) j--;
        if(i<=j)
        {
            swap(b2[x][i][0],b2[x][j][0]);
            swap(b2[x][i][1],b2[x][j][1]);
            swap(b2[x][i++][2],b2[x][j--][2]);
        }
    }
    if(i<r) qsort2(x,i,r);
    if(l<j) qsort2(x,l,j);
}
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int read()
{
	char ch;
	int s=0;
	ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read(),m=read(),p=read();
    for(int i=1;i<=m;i++) b[i][1]=read(),b[i][2]=read(),b[i][0]=read();
    qsort(1,m);
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++)
    {
        if(find(b[i][1])==find(b[i][2])) continue;
        fa[find(b[i][1])]=find(b[i][2]);
        ++tot,c[tot][0]=b[i][0],c[tot][1]=b[i][1],c[tot][2]=b[i][2];
    }
    for(int i=1;i<=p;i++)
    {
        for(int j=0;j<=n;j++) a[i][j]=read();
    }
    for(int i=0;i<32;i++)
    {
        for(int j=1;j<=p;j++)
        {
            if(i&(1<<(j-1)))
            {
                for(int k=1;k<=n;k++)
                {
                    ++l1[i];
                    b1[i][l1[i]][1]=k;
                    b1[i][l1[i]][2]=j+n;
                    b1[i][l1[i]][0]=a[j][k];
                }
            }
            if((i<<5)&(1<<(j-1)))
            {
                for(int k=1;k<=n;k++)
                {
                    ++l2[i];
                    b2[i][l2[i]][1]=k;
                    b2[i][l2[i]][2]=j+n;
                    b2[i][l2[i]][0]=a[j][k];
                }
            }
        }
        qsort1(i,1,l1[i]),qsort2(i,1,l2[i]);
    }
    int S=(1<<p);
    anss=1e18;
    for(int i=1;i<=tot;i++) d[i][0]=c[i][0],d[i][1]=c[i][1],d[i][2]=c[i][2];
    for(int i=0;i<S;i++)
    {
        int p0,p1,p2,sum1=i&31,sum2=i/32,tmpp=tot;
        for(int j=1;j<=tot;j++) tmp[j][0]=d[j][0],tmp[j][1]=d[j][1],tmp[j][2]=d[j][2];
        p0=1,p1=1,p2=1;
        while(p1<=tot&&p2<=l1[sum1])
        {
            if(tmp[p1][0]<b1[sum1][p2][0])
            {
                c[p0][0]=tmp[p1][0],c[p0][1]=tmp[p1][1],c[p0][2]=tmp[p1][2];
                p0++,p1++;
            }
            else
            {
                c[p0][0]=b1[sum1][p2][0],c[p0][1]=b1[sum1][p2][1],c[p0][2]=b1[sum1][p2][2];
                p0++,p2++;
            }
        }
        while(p1<=tot)
        {
            c[p0][0]=tmp[p1][0],c[p0][1]=tmp[p1][1],c[p0][2]=tmp[p1][2];
            p0++,p1++;
        }
        while(p2<=l1[sum1])
        {
            c[p0][0]=b1[sum1][p2][0],c[p0][1]=b1[sum1][p2][1],c[p0][2]=b1[sum1][p2][2];
            p0++,p2++;
        }
        tot=p0;
        for(int j=1;j<=tot;j++) tmp[j][0]=c[j][0],tmp[j][1]=c[j][1],tmp[j][2]=c[j][2];
        p0=1,p1=1,p2=1;
        while(p1<=tot&&p2<=l2[sum2])
        {
            if(tmp[p1][0]<b2[sum2][p2][0])
            {
                c[p0][0]=tmp[p1][0],c[p0][1]=tmp[p1][1],c[p0][2]=tmp[p1][2];
                p0++,p1++;
            }
            else
            {
                c[p0][0]=b2[sum2][p2][0],c[p0][1]=b2[sum2][p2][1],c[p0][2]=b2[sum2][p2][2];
                p0++,p2++;
            }
        }
        while(p1<=tot)
        {
            c[p0][0]=tmp[p1][0],c[p0][1]=tmp[p1][1],c[p0][2]=tmp[p1][2];
            p0++,p1++;
        }
        while(p2<=l2[sum2])
        {
            c[p0][0]=b2[sum2][p2][0],c[p0][1]=b2[sum2][p2][1],c[p0][2]=b2[sum2][p2][2];
            p0++,p2++;
        }
        tot=p0;
        LL ans=0;
        for(int j=1;j<=p;j++) if(i&(1<<(j-1))) ans+=a[j][0];
        for(int j=1;j<=n+p;j++) fa[j]=j;
        for(int j=1;j<=tot;j++)
        {
            if(find(c[j][1])==find(c[j][2])) continue;
            fa[find(c[j][1])]=find(c[j][2]);
            ans+=c[j][0];
        }
        anss=min(anss,ans),tot=tmpp;
    }
    printf("%lld",anss);
}
