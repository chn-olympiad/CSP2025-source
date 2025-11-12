#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N = 5e5 + 10;
int a[N],ans,k,n,b[N];
bool vis[N];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		b[i] = b[i - 1] ^ a[i];
		if(a[i] == k)ans ++,vis[i] = 1;
	}
	if(k == 0){
		for(int i = 1;i <= n;i ++){
			if(vis[i] or vis[i + 1])continue;
			if(a[i] == a[i + 1])ans ++,vis[i] = vis[i + 1] = 1;
		}
	}
	if(k == 1){
		for(int i = 1;i <= n;i ++){
			if(vis[i] or vis[i + 1])continue;
			int x = max(a[i],a[i + 1]);
			int y = min(a[i],a[i + 1]);
			if(x - y == 1)ans ++,vis[i] = vis[i + 1] = 1;
		}
	}
	cout << ans;
	
	return 0;
}


