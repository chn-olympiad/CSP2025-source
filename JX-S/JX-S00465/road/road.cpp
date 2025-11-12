#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e4+2;
ll m,n,k;
bool isdl[N];
vector<int> p[N];
vector<int> wht[N];
bool islt[N][100];
struct xz{
	ll pce;
	int a[N];
}x[11];
ll cost;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		p[u].push_back(v);
		p[v].push_back(u);
		wht[u].push_back(w);
		wht[v].push_back(w);
	}
	for(int i=1;i<=k;i++){
		cin>>x[i].pce;
		for(int j=1;j<=n;j++){
			cin>>x[i].a[j];
		}
	}
	for(int i=1;i<=n;i++){
		int id=0;
		//cout<<"*";
		//cout<<p[i].size()<<endl;
		for(int j=1;j<p[i].size();j++){
			if(wht[i][id]>wht[i][j]){
				id=j;
				//cout<<id<<endl;
			}
		}
		if(islt[i][id]==0){
				cost+=wht[i][id];
				//cout<<cost<<"*";
				islt[i][p[i][id]]=1;
				islt[p[i][id]][i]=1;
			}
	}
	cout<<cost;
	return 0;
}
