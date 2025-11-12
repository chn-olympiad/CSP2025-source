#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define PII pair<int,int> 
const int N=1e5+5;
const int INF=0x3f3f3f3f;
vector<PII>G[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1,x,y,z;i<=n;i++){
		cin>>x>>y>>z;
		G[x].push_back({y,z});
		G[y].push_back({x,z});
		sum+=z;
	}
	cout<<sum<<endl;
	return 0;
}

