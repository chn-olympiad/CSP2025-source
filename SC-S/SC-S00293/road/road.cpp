#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int N=1e6+5;
struct add{
	int u,v,w;
}a[N];
int b[12][N];
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,mn=1e9;
	cin>>n>>m>>k;
	map<pair<int,int>,int>mp;
	for(int i=1;i<=m;i++){
		cin>>a[i].u>>a[i].v>>a[i].w;
		mp[{a[i].u,a[i].v}]=a[i].w;
		mp[{a[i].v,a[i].u}]=a[i].w;
	}
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			cin>>b[i][i];
		}
	}
	int sum=b[0][0];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			sum+=min(mp[{i,j}],b[0][i]+b[0][j]);
		}
	}
	cout<<sum;
	return 0;
} 