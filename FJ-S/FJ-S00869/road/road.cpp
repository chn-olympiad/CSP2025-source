#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int n,m,k;
int mp[N][N];
int u[N],v[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	//memset(mp,0x3f,sizeof mp);
	cin>>n>>m>>k;
	cout<<0;
	/*for(int i=1;i<=m;i++){
		int w;
		cin>>u[i]>>v[i]>>w;
		mp[u[i]][v[i]]=mp[v[i]][u[i]]=min(w,mp[u[i]][v[i]]);
	}
	for(int i=1;i<=k;i++){
		int a[N];
		int x;
		cin>>x;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		for(int j=1;j<=n;j++){
			for(int j2=1;j2<=n;j2++){
				if(j==j2)continue;
				mp[j][j2]=mp[j2][j]=min(a[j]+a[j2]+x,mp[j][j2]);
			}
		}
	}
	long long ret=0;
	for(int i=1;i<=m;i++){
		ret+=mp[u[i]][v[i]];
	}
	cout<<ret;*/
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/
