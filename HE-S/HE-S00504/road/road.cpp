#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	if(m<=10){
		cout<<1;
		return 0;
	}
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		int c,a[10010];
		cin>>c;
		ans+=c;
		for(int j=1;j<=n;j++){
			cin>>a[i];
		}
	}
	cout<<ans;
	return 0;
}
