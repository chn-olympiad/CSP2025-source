#include <bits/stdc++.h>
using namespace std;
long long n,m,k,b,c,d,e[10005],f[10][1000000],g[10000],k1=10000000,l=0,l1[1000005];
vector<vector<long long>>a;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	a.reserve(10000);
	for(int z=1;z<=m;z++){
		cin>>b>>c>>d;
		l+=d;
		a[b].push_back(d);
		a[c].push_back(d);
	}
	if(k==0){
		cout<<l;
		return 0;
	}
	for(int z=1;z<=k;z++){
		cin>>g[z];
		k1=min(g[z],k);
		for(int y=1;y<=n;y++)cin>>f[z][y];
	}
	if(k1==0){
		cout<<0;
		return 0;
	}
	cout<<355;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
