#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct aroad{
	int to;
	long long cost;
}tp;
vector<aroad> r[10100];
long long c[15],a[15][10010];
set<int> h;
int mrf,mrt;
long long mrc=(1e10);
long long ans=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v,w;
	for(int i=1;i<=m;i++){cin>>u>>v>>w;
		tp.to=v;tp.cost=w;r[u].push_back(tp);
		tp.to=u;r[v].push_back(tp);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	if(k==0){
		h.insert(1);
		while(h.size()!=n){
			mrc=1e10;
			for(int i=1;i<=n;i++){
				if(h.find(i)==h.end()){
					for(set<int>::iterator it=h.begin();it!=h.end();it++){
						if(r[i][*it].cost<mrc){
							mrc=r[i][*it].cost;
							mrt=i;mrf=*it;
						}
					}
				}
			}
			h.insert(mrt);ans+=mrc;
		}
	}
	cout<<ans;
	return 0;
}
