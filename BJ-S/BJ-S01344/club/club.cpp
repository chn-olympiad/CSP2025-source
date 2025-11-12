#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

struct node{
	long long val,id;
}a[N],b[N],c[N];
int dp[N][10];

bool vis[N];

bool cmp(node a,node b){
	return a.val > b.val;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--){
		memset(vis,0,sizeof(vis));
		long long ans = 0;
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].val >> b[i].val >> c[i].val;
			a[i].id = b[i].id = c[i].id = i;	
		}
		if(n == 2){
			long long mx = 0;
			mx = max(mx,a[1].val + b[2].val);
			mx = max(mx,a[2].val + b[1].val);
			mx = max(mx,a[1].val + c[2].val);
			mx = max(mx,a[2].val + c[1].val);
			mx = max(mx,b[1].val + c[2].val);
			mx = max(mx,b[2].val + c[1].val);
			
			mx = max(mx,a[1].val + a[2].val);
			mx = max(mx,b[1].val + b[2].val);
			mx = max(mx,c[1].val + c[2].val);
			ans = mx;
			cout << ans;
			return 0;
		}
		for(int i = 1;i <= n;i++){
			ans += a[i].val;
		}
		cout << ans << '\n';
	}
	
	return 0;
}
