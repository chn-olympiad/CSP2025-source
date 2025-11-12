#include<bits/stdc++.h>
using namespace std;
/*
优先队列表示最抢手的社团中，最小的差值
相等的情况： 
*/
const int N = 1e6 + 5;
int a[N],b[N],c[N];
int A,B,C;
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		A = B = C = 0;
		int n;
		cin >> n;
		for(int i = 1;i <= n;i++) {
			cin >> a[i] >> b[i] >> c[i];
			int res = max({a[i],b[i],c[i]});
			if(res == a[i]) A++;
			if(res == b[i]) B++;
			if(res == c[i]) C++;			
		}
		int mx = max({A,B,C});
		int ansA = 0,ansB = 0,ansC = 0;
		if(mx == A) {
			priority_queue <int> qa;
			for(int i = 1;i <= n;i++) {
				int res = max({a[i],b[i],c[i]});
				ansA += res;
				if(a[i] == res) {
					int res1 = max({b[i],c[i]});
					qa.push(res1 - res);
				}
			}
			while(1) {
				if(qa.size() <= n / 2) break; 
				int x = qa.top();
				qa.pop();
				ansA += x;
			}			
		}
		if(mx == B) {
			priority_queue <int> qb;
			for(int i = 1;i <= n;i++) {
				int res = max({a[i],b[i],c[i]});
				ansB += res;
				if(b[i] == res) {
					int res1 = max({a[i],c[i]});
					qb.push(res1 - res);
				}
			}
			while(1) {
				if(qb.size() <= n / 2) break; 
				int x = qb.top();
				qb.pop();
				ansB += x;
			}			
		}
		if(mx == C) {
			priority_queue <int> qc;
			for(int i = 1;i <= n;i++) {
				int res = max({a[i],b[i],c[i]});
				ansC += res;
				if(c[i] == res) {
					int res1 = max({b[i],a[i]});
					qc.push(res1 - res);
				}
			}
			while(1) {
				if(qc.size() <= n / 2) break; 
				int x = qc.top();
				qc.pop();
				ansC += x;
			}			
		}
		cout << max({ansA,ansB,ansC}  ) << endl;
	}
	return 0;
}

