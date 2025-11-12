#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[5005],ans=0,p[5005];
vector<pair<int,int>> g[5005];

void dfs(int u,int x,int last,int sum,int mx){
	if(u==x+1){
		if(sum>mx*2){
			ans++;
			ans %= 998244353;
//			for(int i=1;i<=x;i++)cout << p[i] << " ";
//			cout << endl;
		}
	}
	for(int i=last+1;i<=n;i++){
//		p[u]=a[i];
		dfs(u+1,x,i,sum+a[i],max(a[i],mx));
	}
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
	
	cin >> n;
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a+1,a+n+1);
//	for(int i=1;i<=n;i++){
//		for(int j=i+1;j<=n;j++){
//			for(int k=j+1;k<=n;k++){
//				if(a[i]+a[j]+a[k]>a[k]*2){
//					g[3].push_back({a[i]+a[j]+a[k],a[k]});
//				}
//			}
//		}
//	}
	for(int i=4;i<=n;i++){
		dfs(1,i,0,0,-1);
//		int l = g[i-1].size();
//		for(int j=0;j<l;j++){
//			for(int i=)
//		}
	}
	cout << ans;
	
	return 0;
}
