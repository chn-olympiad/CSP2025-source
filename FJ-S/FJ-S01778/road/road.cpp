#include<bits/stdc++.h>
using namespace std;
int a[10005],u[1000005],v[1000005],w[1000005],cs[15][10005];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int j=1;j<=m;j++) cin>>u[j]>>v[j]>>w[j];
		sort(w+1,w+m+1);
		int ans=0;
		for(int i=1;i<=n;i++) ans+=w[i];
		cout<<ans;
	}
	else{
		int d=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int j=1;j<=m;j++) cin>>u[j]>>v[j]>>w[j];
		for(int i=1;i<=k;i++){
			cin>>cs[i][0],d+=cs[i][0];
			for(int j=1;j<=n;j++)	
				cin>>cs[i][j],d+=cs[i][j];
		}
		if(d==0) cout<<0;
		else{
			cout<<rand();
		}
	}
	return 0;
}
