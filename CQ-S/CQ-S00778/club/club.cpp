#include <bits/stdc++.h>
#define int long long

using namespace std;

namespace aaaaaa{
	const int N = 1e5 + 5;
	
	struct Node {
		int val;
		int idx;
		
		bool operator > (const Node& x) const {
			return val > x.val;
		}
	};
	
	struct P {
		Node val1;
		Node val2;
		Node val3;
	};
	
	bool compare(P x, P y) {
		return x.val1.val < y.val1.val;
	}
	
	int T;
	int n;
	P a[N];
	
	int cnt[5], s[5];
	priority_queue < Node, vector <Node>, greater <Node> > que[4];
	
	signed main() {
		freopen("club.in", "r", stdin);
		freopen("club.out", "w", stdout);
		
		ios::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
		
		cin >> T;
		while (T --) {
			memset(a, 0, sizeof a);
			memset(cnt, 0, sizeof cnt);
			memset(s, 0, sizeof s);
			
			while (!que[1].empty())
				que[1].pop();
			while (!que[2].empty())
				que[2].pop();
			while (!que[3].empty())
				que[3].pop();
			
			cin >> n;
			for (int i = 1; i <= n; ++ i) {
				cin >> a[i].val1.val >> a[i].val2.val >> a[i].val3.val;
				a[i].val1.idx = 1;
				a[i].val2.idx = 2;
				a[i].val3.idx = 3;
			}
			
			for (int i = 1; i <= n; ++ i) {
				if (a[i].val1.val < a[i].val2.val)
					swap(a[i].val1, a[i].val2);
				if (a[i].val1.val < a[i].val3.val)
					swap(a[i].val1, a[i].val3);
				if (a[i].val2.val < a[i].val3.val)
					swap(a[i].val2, a[i].val3);
	//			cout << "i = " << i << "a[i] = " << a[i].val1.val << ' ' << a[i].val2.val << ' ' << a[i].val3.val << '\n';
			}
			
			sort(a + 1, a + 1 + n, compare);
			
			for (int i = 1; i <= n; ++ i) {			
				if (cnt[a[i].val1.idx] < n / 2) {
	//				cout << 1;
					que[a[i].val1.idx].push({a[i].val1.val, i});
					cnt[a[i].val1.idx] ++;
					s[a[i].val1.idx] += a[i].val1.val;
				} else {
	//				cout << 2;
					Node tmp = que[a[i].val1.idx].top();
					
	//				cout << "tmp = " << tmp.val << ' ' << tmp.idx << '\n';
					
					if (tmp.val < cnt[a[i].val1.val]) {
	//					cout << 3;
						que[a[i].val1.idx].pop();
						
						s[a[i].val1.idx] -= tmp.val;
						if(cnt[a[tmp.idx].val1.idx] < n / 2) {
							cnt[a[tmp.idx].val1.idx] ++;
							s[a[tmp.idx].val1.idx] += a[tmp.val].val2.val;
							que[a[tmp.idx].val1.idx].push({a[tmp.idx].val2.val, tmp.idx});
						} else {
							if(cnt[a[tmp.idx].val2.idx] < n / 2) {
								cnt[a[tmp.idx].val2.idx] ++;
								s[a[tmp.idx].val2.idx] += a[tmp.val].val2.val;
								que[a[tmp.idx].val2.idx].push({a[tmp.idx].val2.val, tmp.idx});
							} else {
								if(cnt[a[tmp.idx].val3.idx] < n / 2) {
									cnt[a[tmp.idx].val3.idx] ++;
									s[a[tmp.idx].val3.idx] += a[tmp.idx].val3.val;
									que[a[tmp.idx].val3.idx].push({a[tmp.idx].val3.val, tmp.idx});
								}
							}
						}
						
						s[a[i].val1.idx] += a[i].val1.val;
					} else {
	//					cout << 4;
						if (cnt[a[i].val2.idx] < n / 2) {
	//						cout << 5;
							que[a[i].val2.idx].push({a[i].val2.val, i});
							cnt[a[i].val2.idx] ++;
							s[a[i].val2.idx] += a[i].val2.val;
						} else {
	//						cout << 6;
							Node tmp1 = que[a[i].val2.idx].top();
							
							if (tmp1.val < cnt[a[i].val2.val]) {
	//							cout << 7;
								que[a[i].val2.idx].pop();
								
								s[a[i].val2.idx] -= tmp1.val;
								if(cnt[a[tmp.idx].val1.idx] < n / 2) {
									cnt[a[tmp.idx].val1.idx] ++;
									s[a[tmp.idx].val1.idx] += a[tmp.val].val2.val;
									que[a[tmp.idx].val1.idx].push({a[tmp.idx].val2.val, tmp.idx});
								} else {
									if(cnt[a[tmp.idx].val2.idx] < n / 2) {
										cnt[a[tmp.idx].val2.idx] ++;
										s[a[tmp.idx].val2.idx] += a[tmp.val].val2.val;
										que[a[tmp.idx].val2.idx].push({a[tmp.idx].val2.val, tmp.idx});
									} else {
										if(cnt[a[tmp.idx].val3.idx] < n / 2) {
											cnt[a[tmp.idx].val3.idx] ++;
											s[a[tmp.idx].val3.idx] += a[tmp.idx].val3.val;
											que[a[tmp.idx].val3.idx].push({a[tmp.idx].val3.val, tmp.idx});
										}
									}
								}
								
								s[a[i].val2.idx] += a[i].val2.val;
							} else {
	//							cout << 8;
								if (cnt[a[i].val3.idx] < n / 2) {
	//								cout << 9;
									que[a[i].val3.idx].push({a[i].val3.val, i});
									cnt[a[i].val3.idx] ++;
									s[a[i].val3.idx] += a[i].val3.val;
								}
							}
						}
					}
				}
	//			printf("i = %d s[1] = %d s[2] = %d s[3] = %d cnt[1] = %d cnt[2] = %d cnt[3] = %d\n", i, s[1], s[2], s[3], cnt[1], cnt[2], cnt[3]); 
			}
			
			cout << s[1] + s[2] + s[3] << '\n';
		}
		
		return 0;
	} 
}

signed main() {
	aaaaaa::main();
	 
	return 0;
}
