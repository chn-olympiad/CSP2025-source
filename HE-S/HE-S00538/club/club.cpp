#include<bits/stdc++.h>
#define ll long long
const int N = 1e5 + 10;
using namespace std;
int T,n;
int vis[N];
struct node {
	int a,b,c,id,k;
};
bool cmp (node x,node y) {
	return x.a > y.a;
}
bool cmp1 (node x,node y) {
	return (x.b-x.a) > (y.b - y.a);
}
bool cmp2 (node x,node y) {
	return x.k > y.k;
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while (T--) {
		cin >> n;
		int ans = 0;
		bool ok1 = false,ok2 = false;
		for (int i = 1; i <= n; ++i) vis[i] = 1;
		
		vector <node> vec(n+10,{0,0,0,0,0});
		
		for (int i = 1; i <= n; ++i) {
			cin >> vec[i].a >> vec[i].b >> vec[i].c;
			vec[i].id = i;
			if ((vec[i].c != 0 || vec[i].b != 0) && !ok1) ok1 = true;
			if (vec[i].c != 0 && !ok2) ok2 = true;
		}
		
	    if (!ok2) {
			for (int i = 1; i <= n; ++i) ans += vec[i].a;
			sort (vec.begin()+1,vec.begin()+1+n,cmp1);
			for (int i = 1; i <= n/2; ++i) {
				ans += vec[i].b - vec[i].a;
			}
			cout << ans << '\n';
		}else if (!ok1) {
			sort (vec.begin()+1,vec.begin()+1+n,cmp);
			for (int i = 1; i <= n/2; ++i) ans += vec[i].a;
			cout << ans << '\n';
		}
		else if (n == 2) {
			int a1 = vec[1].a,a2 = vec[2].a,b1 = vec[1].b,b2 = vec[2].b,c1 = vec[1].c,c2 = vec[2].c;
			ans = max({a1 + b2,a1+c2,b1+a2,b1+c2,c1+a2,c1+b2});
			cout << ans << '\n';	
		}
		else {
			for (int i = 1; i <= n; ++i) ans += vec[i].a;
			sort (vec.begin()+1,vec.begin()+1+n,cmp1);
			for (int i = 1; i <= n/2; ++i) {
				ans += vec[i].b - vec[i].a;
				vis[vec[i].id] = 2;
			}
			for (int i = 1; i <= n; ++i) {
				int temp1 = 0;
				if (vis[vec[i].id] == 1) temp1 = vec[i].c - vec[i].a;
				else temp1 = vec[i].c - vec[i].b;
				vec[i].k = temp1;				
			}
			sort (vec.begin()+1,vec.begin()+1+n,cmp2);			
			int cnt = 0;
			for (int i = 1; i <= n/2; ++i) {
				int temp5 = 0;
				if (vis[vec[i].id] == 1) {
					temp5 = vec[i].c - vec[i].a;
					if (temp5 < 0) goto kkk;
					ans += vec[i].c - vec[i].a;
					vis[vec[i].id] = 3;	
					cnt++;
				}
				kkk:;
				if (vis[vec[i].id == 2]){
					temp5 = vec[i].c - vec[i].b;
					if (temp5 < 0) continue;
					ans += vec[i].c - vec[i].a;
					vis[vec[i].id] = 3;
					cnt++;
				}
			}
			for (int i = 1; i <= n; ++i) {
				int temp5 = 0;
				if (cnt >= n/2) break;
				if (vis[vec[i].id == 2]){
					temp5 = vec[i].b - vec[i].a;
					if (temp5 > vec[i].k) continue;
					vis[vec[i].id] = 3;
					cnt++;
				}
			}
			for (int i = 1; i <= n; ++i) {
				int temp5 = 0;
				if (cnt >= n/2) break;
				if (vis[vec[i].id == 1]){
					temp5 = vec[i].a;
					if (temp5 > vec[i].c) continue;
					vis[vec[i].id] = 3;
					cnt++;
				}
			}
			int ans1 = 0;
			for (int i = 1; i <= n; ++i) {
				if (vis[vec[i].id] == 1) ans1 += vec[i].a;
				else if (vis[vec[i].id] == 2) ans1 += vec[i].b;
				else ans1 += vec[i].c;
			}
			cout << ans1 << '\n';
		}
	}
	return 0;
}
