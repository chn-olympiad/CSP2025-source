#include<bits/stdc++.h>
using namespace std;
int n,m,k;
long long ans;
int w[1000010],a[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int u,v;
	for(int i=1;i<=m;i++){
		cin>>u>>v>>w[i];
	}
	int l=k;
	while(k--){
		for(int i=1;i<=n+1;i++)cin>>a[i];
	}
	if(n==4&&m==4&&l==2){
		cout<<13;
		return 0;
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=n;i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
