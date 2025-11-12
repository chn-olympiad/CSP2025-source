#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+9;
int n,m,k;
int f[N],ans,cnt;
struct node{
  int u,v,c;
}a[N];
int finp(int x){
if(f[x]==x) return x;
return f[x]=finp(f[x]);
}
bool cmp(node a,node b){
  return a.c<b.c;
}
signed main(){
   freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //next_permutation()
  cin>>n>>m>>k;
  for(int i=1;i<=m;i++){
    cin>>a[i].u>>a[i].v>>a[i].c;
  }
  sort(a+1,a+n+1,cmp);
  for(int i=1;i<=m;i++){
    int fu=finp(a[i].u),fv=finp(a[i].v);
    if(fu!=fv){
        f[fu]=fv;
        ans+=a[i].c;
        cnt++;
        if(cnt==n-1){
            break;
        }
    }
  }
  cout<<ans;
return 0;
}


