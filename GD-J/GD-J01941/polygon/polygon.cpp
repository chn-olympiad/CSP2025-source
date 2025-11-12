#include <bits/stdc++.h>
using namespace std;
int n,mx,ans,a[10000],f[10000];
void dfs(int dis,int ins,int p,int tot,int ci) {
	if(ins==0) return;
	for(int o=p+1;o<ins;o++) {
		if(a[o]+tot>dis) continue;
		if(ci!=0) ans++;
		dfs(dis,ins,o,tot+a[o],ci+1);
	}
}
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
		f[i]=a[i]+f[i-1];
	for(int i=3;i<=n;i++) {
		if(a[i]>=f[i-1]) continue;
		ans++;
		int jx=(upper_bound(a+1,a+1+n,(f[i-1]-1-a[i]))-a)-1;
		cout<<a[jx]<<'\n';
		ans+=jx;
		dfs(a[jx],jx,0,0,0);
	}
	cout<<(((ans%998)%244)%353);
	return 0;
} 
