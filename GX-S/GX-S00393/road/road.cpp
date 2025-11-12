#include<cstdio>
#include<algorithm>
using namespace std;

const int nn=10104;
const int mm=1000006;
const int KK=10;
const long long INF=0x3f3f3f3f3f3f3f3f;

struct Road{
    int x,y,z;
};
bool cmpR(Road,Road);

int n,m,K;
Road a1[mm];
int b1[KK];
Road b2[KK][nn];

int Find(int);
void ReadyF();
int fa[nn];

long long solve(int,int);
Road c[1<<KK][nn];
int cx[1<<KK];

inline void read(int &x)
{
    char ch=getchar();
    while(ch<48) ch=getchar();
    while(ch>=48)
    {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return;
}

int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    //scanf("%d%d%d",&n,&m,&K);
    read(n);read(m);read(K);
    for(int i=1;i<=m;i++)
    {
        //scanf("%d%d%d",&a1[i].x,&a1[i].y,&a1[i].z);
        read(a1[i].x);read(a1[i].y);read(a1[i].z);
    }
    //for(int i=1;i<=m;i++) if(a1[i].x>n||a1[i].y>n) puts("wrong1");
    for(int i=0;i<K;i++)
    {
        //scanf("%d",&b1[i]);
        read(b1[i]);
        for(int j=1;j<=n;j++)
        {
            //scanf("%d",&b2[i][j].z);
            read(b2[i][j].z);
            b2[i][j].x=j,b2[i][j].y=n+i+1;
        }
    }
    //printf("m-OK1\n");//
    //for(int i=1;i<=m;i++) if(a1[i].x>n||a1[i].y>n) puts("wrong2");

    sort(a1+1,a1+1+m,cmpR);
    for(int i=0;i<K;i++) sort(b2[i]+1,b2[i]+1+n,cmpR);
    //printf("m-OK2\n");//

    long long ans=0;
    ReadyF();
    for(int i=1,fx,fy;i<=m;i++)
    {
        //printf("m-f4-OK0 i=%d x=%d,y=%d\n",i,a1[i].x,a1[i].y);//
        fx=Find(a1[i].x);
        //printf("m-f4-OK1 i=%d fx=%d\n",i,fx);//
        fy=Find(a1[i].y);
        //printf("m-f4-OK2 i=%d fy=%d\n",i,fy);//
        if(fx!=fy) fa[fx]=fy,ans+=a1[i].z,c[0][++cx[0]]=a1[i];
    }
    //printf("m-OK3\n");//

    for(int w=1,zsc=(1<<K);w<zsc;w++)
    {
        //printf("m-f5-OK0 w=%d\n",w);//
        int op=0;
        //printf("m-f5-OK1 w=%d\n",w);//
        while(!(w&(1<<op))) op++;
        //printf("m-f5-OK2 w=%d\n",w);//
        long long jie=solve(w,op);
        for(int i=0;i<K;i++) if(w&(1<<i)) jie+=b1[i];
        if(jie<ans) ans=jie;
    }

    printf("%lld",ans);

    return 0;
}
bool cmpR(Road p1,Road p2)
{
    return p1.z<p2.z;
}
int Find(int x)
{
    //printf("Find-OK0 x=%d\n",x);//
    if(fa[x]==x) return x;
    return fa[x]=Find(fa[x]);
}
void ReadyF()
{
    for(int i=n+K;i;i--) fa[i]=i;
    return;
}
long long solve(int op1,int op2)
{
    ReadyF();
    //printf("solve-OK1 op1=%d,op2=%d\n",op1,op2);//

    long long res=0;

    int l1=1,l2=1,fx,fy;
    while(l1<=cx[op1^(1<<op2)]&&l2<=n)
    {
        if(c[op1^(1<<op2)][l1].z<b2[op2][l2].z)
        {
            fx=Find(c[op1^(1<<op2)][l1].x);
            fy=Find(c[op1^(1<<op2)][l1].y);
            if(fx!=fy) fa[fx]=fy,res+=c[op1^(1<<op2)][l1].z,c[op1][++cx[op1]]=c[op1^(1<<op2)][l1];
            l1++;
        }
        else
        {
            fx=Find(b2[op2][l2].x);
            fy=Find(b2[op2][l2].y);
            if(fx!=fy) fa[fx]=fy,res+=b2[op2][l2].z,c[op1][++cx[op1]]=b2[op2][l2];
            l2++;
        }
    }
    while(l1<=cx[op1^(1<<op2)])
    {
        fx=Find(c[op1^(1<<op2)][l1].x);
        fy=Find(c[op1^(1<<op2)][l1].y);
        if(fx!=fy) fa[fx]=fy,res+=c[op1^(1<<op2)][l1].z,c[op1][++cx[op1]]=c[op1^(1<<op2)][l1];
        l1++;
    }
    while(l2<=n)
    {
        fx=Find(b2[op2][l2].x);
        fy=Find(b2[op2][l2].y);
        if(fx!=fy) fa[fx]=fy,res+=b2[op2][l2].z,c[op1][++cx[op1]]=b2[op2][l2];
        l2++;
    }

    return res;
}
