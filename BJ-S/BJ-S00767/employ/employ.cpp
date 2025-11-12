#include<bits/stdc++.h>
using namespace std;
int n,m,a[12],perm[12],q[12],ans=0;
bool vis[12];
void solve(int dep){
	if(dep==n){
		int nf=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(q[i]&&nf<a[perm[i]])cnt++;
			else nf++;
		}
		if(cnt>=m)ans++;
		return;
	}
	int nd=dep+1;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			perm[nd]=i;
			solve(nd);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	char c;
	for(int i=1;i<=n;i++){
		cin >> c;
		q[i]=c-'0';
	}
	for(int i=1;i<=n;i++)cin >> a[i];
	solve(0);
	cout << ans << endl;
	return 0;
}