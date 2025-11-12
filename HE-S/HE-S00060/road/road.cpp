#include <bits/stdc++.h>
using namespace std;
int n,m,k,ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	cin >>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin >>u>>v>>w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n+1;j++){
			int a;
			cin >>a;
			if(j==1) ans+=a; 
		}
	}cout <<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
