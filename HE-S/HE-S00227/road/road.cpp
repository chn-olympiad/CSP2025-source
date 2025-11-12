#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans;
long long minn=1000000050,minn1=1000000050,minn2=1000000050,minn3=1000000050,minn4=1000000050;
int u[1050],v[1050],c[100];
long long w[1050],a[100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
		} 
	}
	for(int i=1;i<=n;i++){
		if(minn>w[i]){
			minn=w[i];
		}
	}
	ans+=minn;
	for(int i=1;i<=n;i++){
		if(minn1>w[i]&&w[i]!=minn){
			minn1=w[i];
		}
	}
	ans+=minn1;
	for(int i=1;i<=k;i++){
		if(minn2>c[i]){
			minn2=c[i];
		}
	}
	ans+=minn2;
	for(int i=1;i<=n;i++){
		if(minn3>a[i]){
			minn3=a[i];
		}
	}
	ans+=minn3;
	for(int i=1;i<+n;i++){
		if(minn4>a[i]&&a[i]!=minn3){
			minn4=a[i];
		}
	}
	cout<<ans;
	return 0;
}
