#include<bits/stdc++.h>
using namespace std;
const int N=1000025;
long long n,m,k,u[N],v[N],mp[10005][10005],w[N],c[15],s2=0,ans=0,sc=0;
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		mp[u[i]][v[i]] = min(w[i],mp[u[i]][v[i]]);
		mp[v[i]][u[i]] = min(w[i],mp[u[i]][v[i]]);
	}
	for(int i=1;i<=k;i++){
		cin>>c[i];
		sc+=c[i];
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			mp[j][i]=mp[i][j];
			s2++;
		}
	}
	long long s=n+k;
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			if(mp[i][j]==0) mp[i][j]=0x3f3f3f3f;
			if(mp[j][i]==0) mp[j][i]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=s;i++){
		for(int j=1;j<=s;j++){
			for(int l=1;l<=s;l++){
				mp[j][l] = min(mp[j][l+1]+mp[j+1][l],mp[j][l]);
				mp[l][j] = min(mp[l][j+1]+mp[l+1][j],mp[j][l]);
			}
		}
	}
	for(int i=1;i<=s;i++){
		ans+=mp[i][i+1];
	}
	ans+=sc;
	cout<<ans;
	return 0;
}