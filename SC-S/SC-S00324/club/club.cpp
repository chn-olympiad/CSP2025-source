#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e5+5;
int T,n,ans,f[505][505][505],f1[5005][5005];
struct per{int x,y,z;}a[N];
void solve(){
	cin>>n;
	int _a=1,_b=1;
	ans=0;
	for(int i=1;i<=n;++i){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].y)_a=0;
		if(a[i].z)_a=_b=0;
	}
	if(_a){
		vector<int> d;
		for(int i=1;i<=n;++i)d.push_back(a[i].x);
		sort(d.begin(),d.end());
		for(int i=0;i<d.size()/2;++i)ans+=d[i];
		cout<<ans<<"\n";
		return;
	}
	if(_b){
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)f1[i][j]=0;
		for(int i=1;i<=n;++i)f1[0][0]+=a[i].y;
		for(int i=1;i<=n;++i){
			for(int j=0;j<=n/2;++j){
				if(j>i)continue;
				if(j==0)f1[i][j]=max(f1[i-1][j],f1[i][j]);
				else f1[i][j]=max(f1[i-1][j],f1[i-1][j-1]+a[i].x-a[i].y);
			}
		}
		cout<<f1[n][n/2]<<"\n";
		return;
	}
	if(n<=200){
		for(int i=0;i<=n;++i)
			for(int j=0;j<=n;++j)
				for(int k=0;k<=n;++k)f[i][j][k]=0;
		for(int i=1;i<=n;++i)f[0][0][0]+=a[i].z;
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n/2;++j){
				for(int k=0;k<=n/2;++k){
					if(j+k>i)continue;
					if(j==0&&k==0)f[i][j][k]=max(f[i][j][k],f[i-1][j][k]);
					else if(j==0)f[i][j][k]=max(f[i-1][j][k-1]-a[i].z+a[i].y,f[i-1][j][k]);
					else if(k==0)f[i][j][k]=max(f[i-1][j-1][k]-a[i].z+a[i].x,f[i-1][j][k]);
					else f[i][j][k]=max({f[i-1][j-1][k]-a[i].z+a[i].x,f[i-1][j][k-1]-a[i].z+a[i].y,f[i-1][j][k]});
				}
			}
		}
		for(int i=0;i<=n/2;++i)for(int j=0;j<=n/2;++j)if(n-i-j<=n/2)ans=max(ans,f[n][i][j]);
		cout<<ans<<"\n";
		return;
	}
	for(int i=1;i<=n;++i)ans+=max({a[i].x,a[i].y,a[i].z});
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	for(cin>>T;T;T--)solve();
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/