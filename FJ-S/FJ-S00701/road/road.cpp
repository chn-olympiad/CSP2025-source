#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,k;
int u[N],v[N],w[N];
int c,a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("rosd.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	cin>>c;
	for(int i=1;i<=n;i++) cin>>a[i];
	int ans=0;
	for(int i=1;i<=n;i++) ans+=a[i];
	cout<<ans<<endl;
	return 0;
}
