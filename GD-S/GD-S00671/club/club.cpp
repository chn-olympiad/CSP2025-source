#include <bits/stdc++.h>
using namespace std;
#define int long long
struct P{
	int d1, d2, d3;
	int maxd()const{
		return max(d1, max(d2, d3));
	}
	int nxtd()const{
		if(maxd() == d1){
			return max(d2, d3);
		}else if(maxd() == d2){
			return max(d1, d3);
		}else return max(d1, d2);
	}
}A[100005];
struct Node{
	int id, diff;
	bool operator<(const Node& rhs)const{
		return diff > rhs.diff;
	}
};
signed main(){
	ios::sync_with_stdio(false);
	freopen("club.in", "r", stdin);
	
	///////////////////////////
	///////////////////////////
	///////////////////////////
	freopen("club.out", "w", stdout);
	
	
	cin.tie(0);
	
	int t;
	cin >> t;
	while(t--){
		memset(A, 0, sizeof(A));
		int n, cap;
		cin >> n;
		priority_queue<Node> pq1, pq2, pq3;
		cap = n / 2;
		for(int i{1};i<=n;i++){
			cin >> A[i].d1 >> A[i].d2 >> A[i].d3;
		}
		sort(A + 1, A + 1 + n, [](const P& a,const P& b){
			return  a.maxd() > b.maxd();
		});
		int cnt1{}, cnt2{}, cnt3{}, ans{};
		
		for(int i{1};i<=n;i++){
			if(A[i].maxd() == A[i].d1){
				if(cnt1 < cap){
					cnt1++;
					pq1.push(Node{i, A[i].maxd() - A[i].nxtd()});
					ans += A[i].maxd();
				}else{
					if(pq1.top().diff < A[i].maxd() - A[i].nxtd()){
						ans -= pq1.top().diff;
						pq1.pop();
						pq1.push(Node{i, A[i].maxd() - A[i].nxtd()});
						ans += A[i].maxd();
					}else{
						ans += A[i].nxtd();
					}
				}
			}else if(A[i].maxd() == A[i].d2){
				if(cnt2 < cap){
					cnt2++;
					pq2.push(Node{i, A[i].maxd() - A[i].nxtd()});
					ans += A[i].maxd();
				}else{
					if(pq2.top().diff < A[i].maxd() - A[i].nxtd()){
						ans -= pq2.top().diff;
						pq2.pop();
						pq2.push(Node{i, A[i].maxd() - A[i].nxtd()});
						ans += A[i].maxd();
					}else{
						ans += A[i].nxtd();
					}
				}
			}else if(A[i].maxd() == A[i].d3){
				if(cnt3 < cap){
					cnt3++;
					pq3.push(Node{i, A[i].maxd() - A[i].nxtd()});
					ans += A[i].maxd();
				}else{
					if(pq3.top().diff < A[i].maxd() - A[i].nxtd()){
						ans -= pq3.top().diff;
						pq3.pop();
						pq3.push(Node{i, A[i].maxd() - A[i].nxtd()});
						ans += A[i].maxd();
					}else{
						ans += A[i].nxtd();
					}
				}
			}
		}
		
		cout << ans << '\n';
	}
	
	return 0;
}
