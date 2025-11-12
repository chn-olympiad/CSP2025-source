#include<bits/stdc++.h>
using namespace std;
int f[100005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v>>f[i];
	}
	sort(f+1,f+n+1);
	long long ans=0;
	for(int i=1;i<=n;i++) ans+=f[i];
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}
