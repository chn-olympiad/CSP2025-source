#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=601100;

#define ckmax(x,y) ( x=max(x,y) )

inline int read()
{
    int f=1,x=0; char ch=getchar();
    while(!isdigit(ch)) {  if(ch=='-') f=-1; ch=getchar(); }
    while(isdigit(ch))  {  x=x*10+ch-'0';    ch=getchar(); }
    return f*x;
}

int n,ans;
int a[N][3];

void dfs(int i,int x,int y,int z,int sum)
{
    if(i>n) return (void)( ckmax(ans,sum) );
    if(x<n/2) dfs(i+1,x+1,y,z,sum+a[i][0]);
    if(y<n/2) dfs(i+1,x,y+1,z,sum+a[i][1]);
    if(z<n/2) dfs(i+1,x,y,z+1,sum+a[i][2]);
}

int tmp[N];

struct node
{
    int pos,x,w;
    bool operator < (const node &t)const
    { return w>t.w; }
}p[N];
int tot=0,cnt[3];
bool vis[N];

signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int qQ=read();
    while(qQ--)
    {
        n=read();ans=0;
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++)
        {
            int x=read(),y=read(),z=read();
            a[i][0]=x,a[i][1]=y,a[i][2]=z;
            cnt1+=(!y && !z);
            cnt2+=(!z);
        }
        if(cnt1==n || cnt2==n)
        {
            for(int i=1;i<=n;i++) tmp[i]=a[i][0];
            sort(tmp+1,tmp+n+1);
            for(int i=n;i>=n/2;i--)
              ans+=tmp[i];
        }
        else dfs(1,0,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}

