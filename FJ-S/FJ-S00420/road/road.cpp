#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
typedef long long ll;
ll n,m,k,u[N],v[N],w[N],a[N][N],ans;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		ans+=w[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=m+1;j++){
			cin>>a[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
