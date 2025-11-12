/*
感觉像是贪心

n 一定为偶数 

设集合A是选1的，设集合B是选2的，集合C是选3的。
size(A) = a, size(b) = b, size(c) = (n - a - b)

1. a < ((n) / 2)
2. b < ((n) / 2)
3. (a + b) > ((n) / 2)

40分钟了，先打O(n^2) 做法吧 

速度太慢了，先做第2题

没打出来O(n^2)做法，要完蛋了 
*/
#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10;

int t, n;
int a[N], b[N], c[N];
struct node{
	int id, val;
	
	bool operator < (const node b){
		return val > b.val;
	}
}diff_ab[N], diff_ac[N]; 
int pre_ab[N], pre_ac[N];

bool cmp(int a, int b){
	return a > b;
}

inline void clear(){
	memset(a, 0, sizeof(a)), memset(b, 0, sizeof(b)), memset(c, 0, sizeof(c));
	memset(diff_ab, 0, sizeof(diff_ab)), memset(diff_ac, 0, sizeof(diff_ac));
	memset(pre_ab, 0, sizeof(pre_ab)), memset(pre_ac, 0, sizeof(pre_ac));
}

signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	cin >> t;
	while(t --){
		clear();
		
		int sum = 0, ans = 0;
		bool flag1 = false, flag2 = false; 
		
		cin >> n;
		for(int i = 1; i <= n; ++ i){
			cin >> a[i] >> b[i] >> c[i];
			
			if(b[i]) flag1 = true;
			if(c[i]) flag2 = true;
			
			sum += a[i];
			diff_ab[i] = (node){i, b[i] - a[i]};
			diff_ac[i] = (node){i, c[i] - a[i]};
		}
		
		if(!flag2){
			if(!flag1){//性质A 
				sort(a + 1, a + n + 1, cmp);
				for(int i = 1; i <= (n >> 1); ++ i) ans += a[i];
				cout << ans << '\n';
			}
			else{//性质B 
				sort(diff_ab + 1, diff_ab + n + 1);
				for(int i = 1; i <= (n >> 1); ++ i) sum += diff_ab[i].val;
				cout << sum << '\n';
			}
			continue;
		}
		
		sort(diff_ab + 1, diff_ab + n + 1);
		sort(diff_ac + 1, diff_ac + n + 1);
		
		for(int i = 1; i <= n; ++ i) pre_ab[i] = pre_ab[i - 1] + diff_ab[i].val;
		for(int i = 1; i <= n; ++ i) pre_ac[i] = pre_ac[i - 1] + diff_ac[i].val;
		
		int m = (n >> 1);
		for(int i = 1; i <= m; ++ i){
			for(int j = m - i; j <= m; ++ j){
				int k = n - i - j;
				ans = max(ans, sum + pre_ab[j] + pre_ac[k]);
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
