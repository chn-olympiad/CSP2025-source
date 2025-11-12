#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
   freopen("road.in","r",stdin);
   freopen("road.out","w",stdout);
  cin>>n>>m>>k;
  long long res=0;
  for(int i=1;i<=m;i++){
  	int x,y,w;
  	cin>>x>>y>>w;
  	res+=w;
  }
  for(int i=1;i<=k;i++){
  	int a;
  	cin>>a;
   for(int j=1;j<=n;j++) cin>>a;
  }
  cout<<res;
  return 0;
}


