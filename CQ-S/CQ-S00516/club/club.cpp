#include<bits/stdc++.h>
using namespace std;
namespace cqsunny{
	int T, n;
	struct node{
		int x, y, z, maxn, cr, bh;
		friend bool operator<(node p, node q){
			if(p.cr == q.cr) return p.bh < q.bh; 
			return p.cr > q.cr;
		}
	}a[100010];
	struct node2{
		int x, y, z, maxn, cr, bh;
	}b[100010];
	bool cmp(node2 p, node2 q){
		if(p.maxn == q.maxn) return p.bh < q.bh;
		return p.maxn > q.maxn;
	}
	priority_queue<node> pq1, pq2, pq3; 
	int main(){
		scanf("%d", &T);
		while(T --){
			while(!pq1.empty()) pq1.pop();
			while(!pq2.empty()) pq2.pop();
			while(!pq3.empty()) pq3.pop();
			scanf("%d", &n);
			for(int i = 1; i <= n; ++ i){
				scanf("%d %d %d", &b[i].x, &b[i].y, &b[i].z);
				b[i].maxn = max(b[i].x, max(b[i].y, b[i].z));
				b[i].bh = i; 
			} 
			sort(b + 1, b + n + 1, cmp);
			for(int i = 1; i <= n; ++ i){
				a[i].x = b[i].x, a[i].y = b[i].y, a[i].z = b[i].z;
				a[i].maxn = b[i].maxn, a[i].bh = b[i].bh;
			}
			int l1 = 0, l2 = 0, l3 = 0, ans = 0;
			for(int i = 1; i <= n; ++ i){
	//			printf("%d %d %d %d %d %d %d\n", i, a[i].x, a[i].y, a[i].z, l1, l2, l3);
				if(a[i].x == a[i].maxn){
					++ l1; 
					ans += a[i].x;
					a[i].cr = a[i].x - max(a[i].y, a[i].z);
					pq1.push(a[i]);
					if(l1 > n / 2){
						node t = pq1.top();
						pq1.pop();
						-- l1;
						ans -= t.cr;
						t.x = 0;
						t.maxn = max(t.y, t.z);
						t.cr = t.maxn - min(t.y, t.z);
						if(t.y == t.maxn){
							pq2.push(t);
							++ l2;
						}
						else{
							pq3.push(t);
							++ l3;
						}
					}
				}
				else if(a[i].y == a[i].maxn){
					++ l2; 
					ans += a[i].y;
					a[i].cr = a[i].y - max(a[i].x, a[i].z);
					pq2.push(a[i]);
					if(l2 > n / 2){
						node t = pq2.top();
						pq2.pop();
						ans -= t.cr;
						-- l2;
						t.y = 0;
						t.maxn = max(t.x, t.z);
						t.cr = t.maxn - min(t.x, t.z);
						if(t.x == t.maxn){
							pq1.push(t);
							++ l1;
						}
						else{
							pq3.push(t);
							++ l3;
						}
					}
				}
				else{
					++ l3; 
					ans += a[i].z;
					a[i].cr = a[i].z - max(a[i].x, a[i].y);
					pq3.push(a[i]);
					if(l3 > n / 2){
						node t = pq3.top();
						pq3.pop();
						ans -= t.cr;
						t.y = 0;
						-- l3;
						t.maxn = max(t.x, t.z);
						t.cr = t.maxn - min(t.x, t.z);
						if(t.x == t.maxn){
							pq1.push(t);
							++ l1;
						}
						else{
							pq2.push(t);
							++ l2;
						}
					}
				}
			}
			printf("%d\n", ans);
		}
		return 0;
	} 
} 
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	return cqsunny::main();
}
