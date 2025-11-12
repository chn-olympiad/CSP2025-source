#include<bits/stdc++.h>
#define N 100001
using namespace std;
int read()
{
  int x=0,f=1;char c=getchar();
  while(!isdigit(c))
  {
      if(c=='-') f=-1;
      c=getchar();
  }
  while(isdigit(c))
  {
      x=x*10+c-'0';
      c=getchar();
  }
  return x*f;
}
int T,n;
struct nx
{
  int x,y,z,i;
}a[N];
int t[4][N],cnt[4],num;
long long ans;
int maxx(int x,int y)
{
    return x>y ? x:y;
}
priority_queue<int,vector<int>,greater<int> > q;
void solve(int k)
{
    int m=n/2;
    if(cnt[k]<=m) return;
    if(k==1)
    {
        for(int i=1;i<=cnt[k];i++)
        {
            int p=t[k][i];
            int k=maxx(a[p].y,a[p].z)-a[p].x;
            q.push(k);
        }
        m=cnt[k]-m;
        while(1)
        {
            int l=q.size();
            if(l<=m) break;
            q.pop();
        }
    }
    else if(k==2)
    {
        for(int i=1;i<=cnt[k];i++)
        {
            int p=t[k][i];
            int k=maxx(a[p].x,a[p].z)-a[p].y;
            q.push(k);
        }
        m=cnt[k]-m;
        while(1)
        {
            int l=q.size();
            if(l<=m) break;
            q.pop();
        }
    }
    else
    {
        for(int i=1;i<=cnt[k];i++)
        {
            int p=t[k][i];
            int k=maxx(a[p].x,a[p].y)-a[p].z;
            q.push(k);
        }
        m=cnt[k]-m;
        while(1)
        {
            int l=q.size();
            if(l<=m) break;
            q.pop();
        }
    }
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    T=read();
    while(T--)
    {
        n=read(),ans=num=0;
        cnt[1]=cnt[2]=cnt[3]=0;
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)
        {
            a[i].x=read(),a[i].y=read(),a[i].z=read();
            a[i].i=i;
            if(a[i].x>=a[i].y&&a[i].x>=a[i].z) t[1][++cnt[1]]=i,ans+=a[i].x;
            else if(a[i].y>=a[i].x&&a[i].y>=a[i].z) t[2][++cnt[2]]=i,ans+=a[i].y;
            else t[3][++cnt[3]]=i,ans+=a[i].z;
        }
        for(int j=1;j<=3;j++) solve(j);
        while(!q.empty())
            ans+=q.top(),q.pop();
        printf("%lld\n",ans);
    }
    return 0;
}
