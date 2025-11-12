#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N][N],b[N][N];
int n,m,k;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x][y]=a[y][x]=z;
		ans+=z;
	}
	for(int i=1;i<=k;i++){
		int k1;
		cin>>k1;
		ans+=k1;
		for(int j=1;j<=n;j++){
			int x;
			cin>>x;
			b[i][x]=b[i][k1]=k1+x;
			ans+=x;
		}
	}
	cout<<ans<<endl;
	return 0;
}
/*Ren5Jie4Di4Ling5%*/
