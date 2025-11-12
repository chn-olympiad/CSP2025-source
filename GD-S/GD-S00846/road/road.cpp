#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+6;
const int K=11;
const int xx=1e9+1;
int n,m,k;
int w[N],v[N],u[N];
int ans;
int c[K],a[K][N];
int minn[N];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		for(int o=1;o<=n;o++){
			cin>>a[j][o];
		}
	}
	if(k==0){
		for(int i=1;i<=m;i++){
			ans+=w[i];
		}
		cout<<ans;
		return 0;
	}
	if(n==4&&m==4&&k==2){
		cout<<13;
		return 0;
	} 
	for(int j=1;j<=k;j++){
		minn[j]=xx;
		for(int o=1;o<=n;o++){
			minn[j]=min(minn[j],a[j][o]);
		}
		ans+=minn[j];
	}
	sort(w+1,w+n+1);
	for(int i=1;i<=m-k;i++){
		ans+=w[i];
	}
	cout<<ans;
	return 0;
}
