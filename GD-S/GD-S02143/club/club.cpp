#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 20;
ll t, n, a[N][5], num[5], ans = 0;
ll vis[N], b[N][5];
struct node{
	ll val, to, id;
	bool friend operator < (node a, node b) {return a.val < b.val;}
};
struct node2{
	ll val, to, id;
	bool friend operator < (node2 a, node2 b) {return a.val > b.val;}
};
node find(ll i, ll ex) {
	ll maxx = 0, to;
	node res = (node){0, 0, 0};
	for(int j = 1; j <= 3; j++) {
		if(j == ex) continue;
		if(a[i][j] > maxx) maxx = a[i][j], to = j; 
	}
	res = (node){maxx, to, i};
	return res;
}
priority_queue<node> Q;
priority_queue<node2> q[15];
ll quick_pow(ll a, ll x) {
	ll res = 1;
	while(x) {
		if(x&1) res = res * a;
		a = a*a;
		x>>=1; 
	}
	return res;
}
bool check(ll x, ll p) {
	ll res = 0, i = 0;
	while(i < n) {
		i++;
		if((x%3)+1 == p) res++;
		x /= 3;
	}
	return (res>n/2);
}
ll gets(ll x) {
	ll res = 0, i = 0;
	while(i < n) {
		i++;
		ll j = (x%3) + 1;
		res += a[i][j];
		x /= 3;
	}
	return res;
}
void pt(ll x) {
	ll res = 0, i = 0;
	while(i < n) {
		i++;
		ll j = (x%3) + 1;
		cout << j;
		x /= 3;
//		cout << i << " ";
	}
//	return res;
}
void sub1(){
	ll maxx = 0, ch;
		for(int i = 0; i <= quick_pow(3, n); i++) {
			bool flag = 0;
			ll res = 0;
			for(int j = 1; j <= 3; j++) flag |= check(i, j);
			if(flag == 1) continue;
			res = gets(i);
			if(maxx < res) maxx = max(maxx, res), ch = i;
		}
		cout << maxx << endl;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while(t--) {
		
		cin >> n;
		ans = 0;
		num[1] = num[2] = num[3] = 0;
		for(int i = 1; i <= n; i++) vis[i] = 0;
		
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= 3; j++) {
				cin >> a[i][j];
				Q.push((node){a[i][j], j, i});
			}
		}
		if(n <= 10) sub1();
		else {
			while(!Q.empty()) {
			node now = Q.top();
			Q.pop();
			if(vis[now.id] != 0) continue;
			if(num[now.to] >= n/2) {
//				cout << now.id << " " << now.val << endl;
				node2 ch = q[now.to].top();
				
//				cout << ch.id << " " << ch.val << endl;
//				
//				cout << now.id << " " << x.val+now.val << "---" << ch.val << endl;
				if(now.val > ch.val) {
//					cout << now.id << " " << ch.id << endl;
					q[now.to].pop();
					ans += now.val - ch.val;
					vis[now.id] = now.to;
					vis[ch.id] = ch.to;
					num[ch.to] ++;
					node x = find(now.id, now.to);
					q[now.to].push((node2){now.val-x.val, x.to, now.id});
//					q[now.to].push((node2){now.val, now.to, now.id});
//					q[ch.to].push((node2){x.val, x.to, x.id}); ??
					
				}
				else continue;
			}
			else {
				ans += now.val;
//				cout << now.val << endl;
				vis[now.id] = now.to;
				num[now.to] ++;
				node x = find(now.id, now.to);
				
				q[now.to].push((node2){now.val-x.val, x.to, now.id});
			}
			
			
		}
		for(int j = 1; j <= 3; j++) while(!q[j].empty()) q[j].pop();
//		for(int i = 1; i <= n; i++) cout << vis[i];
//		cout << endl;
		cout << ans << endl;
		}

	}
	return 0;
} 
/*
1
30
10424 1888 2199
17649 15804 14198
10138 18538 13467
6761 3083 2293
15041 10863 4222
14340 5758 4300
19996 18929 18297
10926 3304 2176
7141 10829 10956
13607 4376 14108
16686 9725 6258
4434 18794 4926
11129 10938 790
8722 4648 9466
8433 9585 14771
14115 7600 2137
13059 4853 4038
16361 10577 6964
11071 2792 4531
19225 16563 12240
4933 7500 11108
13470 7273 3969
19927 15477 7010
13889 8913 284
16346 8745 3469
4832 9878 2776
11723 6399 3415
13453 19859 13711
10335 7892 6192
19584 11583 14062
*/
