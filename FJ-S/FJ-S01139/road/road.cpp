#include<cstdio>
#include<iostream>
using namespace std;
int u[100005],v[100005],w[100005],c[15];
int a[10005][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,ans=0;
	bool cc=true,aa=true;
	cin >> n >> m >> k;
	for(int i=1;i<=m;i++){
		cin >> u[i] >> v[i] >> w[i];
	}
	for(int i=1;i<=k;i++){
		cin >> c[i];
		if(c[i]){
			cc=false;
		}
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			if(a[i][j]){
				aa=false;
			}
		}
	}
	if(cc && aa){
		for(int i=1;i<=m;i++){
		    if(u[i]>k && v[i]>k){
		    	ans+=w[i];
			}
		}
	}else{
		
	}
	cout << ans;
	return 0;
}
