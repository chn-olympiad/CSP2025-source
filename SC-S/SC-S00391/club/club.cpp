#include<bits/stdc++.h>
#define int long long 
#define endl "\n"
using namespace std;
vector<int> c1,c2,c3;
int n;
const int N = 1e5 + 10;
struct node {
	int a,b,c;
}A[N]; 
int ans;
bool cmp(node x,node y) {
	return x.a > y.a;
}
void dfs(int now) {
	if(now == n + 1) {
		int res = 0;
		for(auto i : c1) {
			res += i;
		}
		for(auto i : c2) {
			res += i;
		}
		for(auto i : c3) {
			res += i;
		}
		ans = max(ans,res);
		return ;
	}
	if(c1.size() < (n / 2)) {
		c1.push_back(A[now].a);
	    dfs(now + 1);
		reverse(c1.begin(),c1.end());
		c1.erase(c1.begin());
		reverse(c1.begin(),c1.end());
	}
	if(c2.size() < (n / 2)) {
		c2.push_back(A[now].b);
		dfs(now + 1);
		reverse(c2.begin(),c2.end());
		c2.erase(c2.begin());
		reverse(c2.begin(),c2.end());
	}
	if(c3.size() < (n / 2)) {
		c3.push_back(A[now].c);
		dfs(now + 1);
		reverse(c3.begin(),c3.end());
		c3.erase(c3.begin());
		reverse(c3.begin(),c3.end());
	}
}
signed main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios :: sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		cin >> n;
		ans = -1;
		int cnt = 0;
		for(int i=1;i<=n;i++) {
			cin >> A[i].a >> A[i].b >> A[i].c;
			cnt += A[i].b + A[i].c;
		}
		if(cnt == 0){
			sort(A + 1,A + n + 1,cmp);
			for(int i=1;i<=n/2;i++) {
				ans += A[i].a;
			}
			cout << ans << endl;
		}else {
			dfs(1);
			cout << ans << endl;
			continue;
		}
	}
}