#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define int long long
using namespace std;
const int K = 15;
const int N = 1e4+10;
int n,m,k;
struct road{
  int u;
  int v;
  int w;
};
vector<road> roads;
bool cmp(road a,road b){
  return a.w<b.w;
}
//cost
int rural[K][N];
int upgrade_cost[K];
int ans = 1e12;
int uni[N+K];
int getfa(int x){
  if(uni[x]==0){
    return x;
  }
  uni[x] = getfa(uni[x]);
  return uni[x];
}
road rroad[N*K];
int rp=0;
void krusal(int ret){
  //  cout<<"start:"<<second.size()<<endl;
  memset(uni,0,sizeof(uni));
  int p1=0,p2=0;
  while(p1<roads.size()||p2<rp){
    auto f = road{-1,-1,1<<30};
    auto s = road{-1,-1,1<<30};
    if(p1<roads.size()){
      f = roads[p1];
    }
    if(p2<rp){
      s = rroad[p2];
    }
    if(s.w<f.w){
      p2++;
      if(getfa(s.u)!=getfa(s.v)){
	//	cout<<s.u<<' '<<s.v<<endl;	
	uni[getfa(s.u)] = getfa(s.v);
	ret +=s.w;
	continue;
      }
    }
    else{
      p1++;
      if(getfa(f.u)!=getfa(f.v)){
	//	cout<<f.u<<' '<<f.v<<endl;
	uni[getfa(f.u)] = getfa(f.v);
	ret += f.w;
	continue;
      }
    }
  }
  ans = min(ans,ret);
}
void search(int now,int cost ){
  if(now == k+1){
    sort(rroad,rroad+rp,cmp);    
    krusal(cost);
    return ;
  }
  search(now+1,cost);
  for(int j = 1;j<=n;j++){
    rroad[rp++] = {n+now,j,rural[now][j]};
  }
  search(now+1,cost+upgrade_cost[now]);
  rp-=n;
}
signed main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);  
  cin>>n>>m>>k;
  for(int i = 0;i<m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    roads.push_back({u,v,w});
  }
  sort(roads.begin(),roads.end(),cmp);
  bool suba = true;
  for(int i =1;i<=k;i++){
    cin>>upgrade_cost[i];
    if(upgrade_cost[i]!=0)suba=false;
    for(int j = 1;j<=n;j++){
      cin>>rural[i][j];
    }
  }
  if(suba){
    for(int i =1;i<=k;i++){
      for(int j = 1;j<=n;j++){
	 rroad[rp++] = {n+i,j,rural[i][j]};
      }
  }
    sort(rroad,rroad+rp,cmp);
    krusal(0);
  }
  else search(1,0);
  cout<<ans<<endl;
  return 0;
}

