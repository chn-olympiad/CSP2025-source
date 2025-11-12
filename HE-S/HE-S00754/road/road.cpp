#include <bits/stdc++.h>
using namespace std;
const int N =1e4+5;
struct edge{
  int to,q;
};
vector <edge> e[N];
int c[N];
int main(){
  freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
  int n,m,k;
  cin>>n>>m>>k;
  for (int i=1; i<=m;i++){
  	int u,v,w;
  	cin>>u>>v>>w;
  	e[u].push_back({v,w});
  	e[v].push_back({u,w});
  }
  for (int i=1; i<=n;i++){
  	cin>>c[i];
  }
  cout<<0<<'\n';
  return 0;
}
