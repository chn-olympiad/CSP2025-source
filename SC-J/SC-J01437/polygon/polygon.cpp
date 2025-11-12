#include <bits/stdc++.h>
//#define int long long
using namespace std;

const int MOD = 998244353;

const int N  = 5010;

int a[N],pre[N];

int ans = 0;
int n;
void dfs(int now,int sum,int k,int mx) {
//	cout<<now<<" "<<sum<<" "<<k<<" "<<mx<<endl;
//	if(sum<=mx*2) return;
	if(now > n) {
		
		if(k>=3&&sum>mx*2){
//			cout<<now<<" "<<sum<<" "<<k<<" "<<mx<<endl;
			ans++;
			if(ans >=MOD) ans -= MOD;
		}
		return;
	}
	dfs(now+1,sum,k,mx);
	mx = max(mx,a[now]);
	dfs(now+1,sum+a[now],min(3,k+1),mx);
}

//长度和为j且结尾为i
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) ,cout.tie(0);
	cin>>n;
	for(int i =1;i <= n;i++) {
		cin>>a[i];
		pre[i] = pre[i-1] + a[i];
	}
	dfs(1,0,0,0);
//	dfst(1,0,0);
	cout<<ans;
	return 0;
}