#include<bits/stdc++.h>
using namespace std;
#define N 10011
#define M 1000001
#define ll long long
int n,m,k,fa[N],c[11],a[11][N],p[11][N],b[N];
ll ans=1e17;
struct dat{
  int x,y,z;
}now[M];
struct va{
  dat e[N<<1];
  int tt;
}v[1<<10];
int get(int x){
  return fa[x]==x?x:fa[x]=get(fa[x]);
}
bool cmp(dat x,dat y){
  return x.z<y.z;
}
bool cmpp(int x,int y){
  return b[x]<b[y];
}
int read(){
  char c;int x=0;
  for(c=getchar();!isdigit(c);c=getchar());
  for(;isdigit(c);c=getchar())x=x*10+(c^48);
  return x;
}
void kru(int X){
  for(int i=1;i<=n+k;++i)fa[i]=i;
  v[X].tt=0;
  ll sum=0;
  for(int i=0;i<k;++i)if((X>>i)&1)sum+=c[i+1];
  for(int i=1;i<=m;++i){
    int x=now[i].x,y=now[i].y,z=now[i].z;
    x=get(x);y=get(y);
    if(x==y)continue;
    sum+=z;fa[x]=y;
    ++v[X].tt;v[X].e[v[X].tt]=now[i];
  }
  ans=min(ans,sum);
}
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  n=read();m=read();k=read();
  for(int i=1;i<=m;++i){
    now[i].x=read();now[i].y=read();now[i].z=read();
  }
  sort(now+1,now+m+1,cmp);
  for(int i=1;i<=k;++i){
    c[i]=read();
    for(int j=1;j<=n;++j){
      a[i][j]=read();p[i][j]=j;b[j]=a[i][j];
    }
    sort(p[i]+1,p[i]+n+1,cmpp);
  }
  kru(0);
  for(int i=1;i<(1<<k);++i){
    int d=(i^(i&(-i))),c=0;
    for(int j=0;j<k;++j){
      if((i>>j)&1){c=j+1;break;}
    }
    m=0;
    int ij=1,ik=1;
    while(ij<=v[d].tt&&ik<=n){
      if(v[d].e[ij].z<a[c][p[c][ik]])now[++m]=v[d].e[ij++];
      else {now[++m]=(dat){n+c,p[c][ik],a[c][p[c][ik]]};++ik;}
    }
    while(ij<=v[d].tt){
      now[++m]=v[d].e[ij++];
    }
    while(ik<=n){
      now[++m]=(dat){n+c,p[c][ik],a[c][p[c][ik]]};++ik;
    }
    kru(i);
  }
  printf("%lld\n",ans);
  return 0;
}
