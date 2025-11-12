#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,k,ans;

int fa[10020];

int get(int x){
  if(fa[x]==x) return x;
  return fa[x]=get(fa[x]);
}

struct node{
  int u,v,w;
  bool operator < (const node &t){
    return w<t.w;
  }
}a[2000001];

signed main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  ios::sync_with_stdio(0);cin.tie(0);

  cin>>n>>m>>k;

  if(k==0){

    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
      cin>>a[i].u>>a[i].v>>a[i].w;
    }

    sort(a+1,a+m+1);

    for(int i=1;i<=m;i++){
      int u=a[i].u,v=a[i].v,w=a[i].w;
      int x=get(u),y=get(v);
      if(x!=y){
        fa[x]=y;
        ans+=w;
      }
    }

    cout<<ans<<'\n';

  }

  else{
    for(int i=1;i<=n+k;i++) fa[i]=i;
    for(int i=1;i<=m;i++){
      cin>>a[i].u>>a[i].v>>a[i].w;
    }

    int cnt=m;

    for(int i=1;i<=k;i++){
      int c;cin>>c;
      for(int j=1;j<=n;j++){
        int w;cin>>w;
        if(w==0){
          fa[get(n+i)]=get(j);
        }
        else{
          a[++cnt]={n+i,j,w};
        }
      }
    }

    sort(a+1,a+cnt+1);

    for(int i=1;i<=cnt;i++){
      int u=a[i].u,v=a[i].v,w=a[i].w;
      int x=get(u),y=get(v);
      if(x!=y){
        fa[x]=y;
        ans+=w;
      }
    }

    cout<<ans<<'\n';

  }


}