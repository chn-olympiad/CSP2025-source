#include<bits/stdc++.h>
using namespace std;
int n,m,k,lu[10001][10001],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)lu[i][j]=1000000000;
	for(int i=0,u,v,w;i<m;i++){
		cin>>u>>v>>w;
		lu[min(u,v)][max(u,v)]=w;
	}
	for(int i=0,c,a[10001];i<k;i++){
		cin>>c;
		for(int j=0;j<n;j++)cin>>a[i];
		for(int j=0;j<n-1;j++)
			for(int z=j+1;z<n;z++)
				lu[j][z]=min(lu[j][z],c+a[j]+a[z]);
	}
	for(int i=0,minn=1000000000;i<n-1;i++){
		minn=1000000000;
		for(int j=i+1;j<n;j++){
			minn=min(minn,lu[i][j]);
		}
		ans+=minn;
	}
	cout<<ans;
	return 0;
}
