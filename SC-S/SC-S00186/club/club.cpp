#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;

int n;
int ans = 0;

struct node{
	int A1, A2, A3;
	bool usd = 0;//used 
}a[N];

void mmst(){
	n += 3;
	for(int i = 1;i <= n;i++){
		a[i].A1 = 0;
		a[i].A2 = 0;
		a[i].A3 = 0;
		a[i].usd = 0;
	}
	ans = 0;
}

bool cmp(node a, node b){
	if(a.A1 == b.A1){
		if(a.A2 == b.A2){
			return a.A3 > b.A3;
		}
		return a.A2 > b.A2;
	}
	return a.A1 > b.A1;
}

void dfs(int aa, int bb, int cc, int sum){ //a,b,c部门与满意度总和 
	if(aa == 0 && bb == 0 && cc == 0){
		ans = max(ans, sum);
		return ;
	}
	if(aa < 0 || bb < 0 || cc < 0){
		return ;
	}
	for(int i = 1;i <= n;i++){
		if(a[i].usd == 0){
			a[i].usd = 1;
			if(aa >= 1){
				dfs(aa - 1, bb, cc, sum + a[i].A1);
			}
			if(bb >= 1){
				dfs(aa, bb - 1, cc, sum + a[i].A2);
			}
			if(cc >= 1){
				dfs(aa, bb, cc - 1, sum + a[i].A3);
			}
			a[i].usd = 0;
		} 
	}
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		for(int i = 1;i <= n;i++){
			cin >> a[i].A1 >> a[i].A2 >> a[i].A3;
		}
		sort(a + 1, a + 1 + n, cmp);
		for(int i = 1;i <= n / 2;i++){
			for(int j = 1;j <= n / 2;j++){
				int k = n - i - j;
				if(k < n / 2){
					dfs(i, j, k, 0);
				}
			}
		}
		cout << ans << '\n';
		mmst();
	}
	
	return 0;
}