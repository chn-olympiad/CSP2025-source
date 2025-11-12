#include<bits/stdc++.h>
using namespace std;
long long n,m,k,u[1000005],v[1000005],w[1000005],c[15],a[15][10005],ans;
bool flag=true;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		if(c[i]) flag=false;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			if(a[i][j]) flag=false;
		}
	}
	if(flag){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		ans=ans+w[i];
	}
	cout<<ans<<endl;
	return 0;
}
