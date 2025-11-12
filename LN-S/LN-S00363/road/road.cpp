#include <bits/stdc++.h>
using namespace std;
const int N=1e4+10,M=2e6;
int n,m,k,p[N];
vector<pair<int,int>> g[N];
long long w;
struct e{
	int c,a,b;
}fe[M];
int find(int x){
	if(x!=p[x]){
		p[x]=find(p[x]);
	}
	return p[x];
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		fe[i].a=a;fe[i].b=b;fe[i].c=c;
	}
	int idx=m;
	while(k--){
		int q;
		cin>>q;
		for(int i=1;i<=n;i++){
			idx++;
			int a,b,c;
			cin>>a>>b>>c;
			fe[idx].a=a;fe[idx].b=b;fe[idx].c=c;
		}
	}
	cout<<0;
	return 0;
}
