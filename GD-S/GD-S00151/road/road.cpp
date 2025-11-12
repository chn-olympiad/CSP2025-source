#include <bits/stdc++.h>
using namespace std;
int s[1000006];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>s[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int o;
			cin>>o;
		}
	}
	sort(s,s+m);
	int cnt=0;
	int p=(n-k-1>0?n-k-1:0);
	for(int i=1;i<=p;i++){
		cnt+=s[i];
	}
	cout<<cnt;
	return 0;
}
