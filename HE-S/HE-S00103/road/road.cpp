#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int a[10001][10001];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		int ans=0;
		for(int i=1;i<=m;i++){
			int u,v,w;
			cin>>u>>v>>w;
			ans+=w;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
