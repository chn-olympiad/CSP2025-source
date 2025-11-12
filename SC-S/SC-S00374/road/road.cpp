#include<bits/stdc++.h>
using namespace std;
int r[10005][10005];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=0;i<10005;i++){
		for(int j=0;j<10005;j++){
			r[i][j]=2147483647;
		}
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		cin>>r[x][y];
		r[y][x]=r[x][y];
	}
	for(int i=1;i<=k;i++){
		int c;
		cin>>c;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			r[i][j]=min(r[i][j],x);
			r[j][i]=min(r[j][i],x);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int minn=2147483647;
		for(int j=0;j<=i;j++){
			minn=min(minn,r[i][j]);
		}
		ans+=minn;
	}
	cout<<ans;
	return 0;
} 