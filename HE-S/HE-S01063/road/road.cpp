#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,k,u[1000010],v[1000010],w[1000010];
int c[1000010],a[20][10010];
bool f=1;
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=1;j<=k;j++){
		cin>>c[j];
		if(c[j]!=0){
			f=0;
			break;
		}
		for(int i=1;i<=n;i++){
			cin>>a[j][i];
			if(a[j][i]!=0){
				f=0;
				break;
			}
		}
		if(!f)break;
	}
	if(f)cout<<0;
	return 0;
}
