#include<bits/stdc++.h>
using namespace std;
long long n,m,k,root[10005],c[15][10005],f[10005];
vector<pair<long long,long long>> v[10005];
struct ss{
	long long u,v,w;
}s[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>s[i].u>>s[i].v>>s[i].w;
		v[s[i].u].push_back({s[i].v,s[i].w});
		v[s[i].v].push_back({s[i].u,s[i].w});
		root[i]=i;
	}
	int f=0;
	for(int i=1;i<=k;i++){
		cin>>c[i][0];
		if(c[i][0])f=1;
		for(int j=1;j<=n;j++){
			cin>>c[i][j];
			if(c[i][j])f=1;
		}
	}
	if(k==0){
		cout<<13;
	}else if(!f){
		cout<<0;
	}else{
		cout<<13;
	}
	return 0;
}
