#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,k,s[1000100],u[1000100],v[1000100],w[1000100],ans = 0,c[15],a[15][1000100];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	memset(s,0x3f,sizeof(s));
	for (int i = 1;i <= m;i++) {
		cin>>u[i]>>v[i]>>w[i];
		s[u[i]] = min(s[u[i]],w[i]),s[v[i]] = min(s[v[i]],w[i]);
	 }
	for (int i = 1;i <= k;i++){
		cin>>c[i];
		for (int j = 1;j <= n;j++) cin>>a[i][j];
	 }
	for (int i = 1;i <= n;i++) ans += s[i];
	ans /= 2;
	cout<<ans;
	return 0;
 }

