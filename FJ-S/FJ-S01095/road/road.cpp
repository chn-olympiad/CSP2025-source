#include<bits/stdc++.h>
using namespace std;
int n,m,k;
struct city{
	int u,v,w;
};//n->city,m->road,k->countryside
int b[15][10005];
city a[1000005];
int mp[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	if(k>=n-1){
		cout<<0;
		return 0;
		}else if(k==0){
		if(m==n-1){
			int ans=0;
			for(int i=1;i<=m;i++){
				ans+=a[i].w;
			}
			cout<<ans;
			return 0;
		}
		for(int i=1;i<=m;i++){
			mp[a[i].u]=a[i].w;
		}
		sort(mp+1,mp+1+m);
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=mp[i];
		}
		cout<<ans;
		return 0;
	}else{
		for(int i=1;i<=m;i++){
			mp[a[i].u]=a[i].w;
		}
		sort(mp+1,mp+1+m);
		int ans=0;
		for(int i=1;i<=n-k;i++){
			ans+=mp[i];
		}
		cout<<ans;
		return 0;
	}
	
	
	
	
	
	
	
	return 0;
}
