#include <bits/stdc++.h>
using namespace std;
struct member{
	int a, b, c;
}mem[100005];
int ai, bi, ci, ans = 0;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		ans = 0, ai = 0, bi = 0, ci = 0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> mem[i].a >> mem[i].b >> mem[i].c;
		}
		sort(mem + 1, mem + n + 1, [&](member x, member y){
			if(x.a != y.a) return x.a > y.a;
			else if(x.b != y.b) return x.b > y.b;
			else return x.c > y.c;
		});
		for (int i = 1; i <= n; i++){
			int maxx = max({mem[i].a, mem[i].b, mem[i].c});
			if(maxx == mem[i].a){
				if(ai < n / 2) ai++, ans += mem[i].a;
				else{
					int maxy = max(mem[i].b, mem[i].c);
					if(maxy == mem[i].b){
						if(bi < n - 2) bi++, ans += mem[i].b;
						else ci++, ans += mem[i].c;
					}else ci++, ans += mem[i].c;
				}
			}else if(maxx == mem[i].b){
				if(bi < n / 2) bi++, ans += mem[i].b;
				else{
					int maxy = max(mem[i].a, mem[i].c);
					if(maxy == mem[i].a){
						if(ai < n - 2) ai++, ans += mem[i].a;
						else ci++, ans += mem[i].c;
					}else ci++, ans += mem[i].c;
				}
			}else if(maxx == mem[i].c){
				if(ci < n / 2) ci++, ans += mem[i].c;
				else{
					int maxy = max(mem[i].a, mem[i].b);
					if(maxy == mem[i].a){
						if(ai < n - 2) ai++, ans += mem[i].a;
						else bi++, ans += mem[i].b;
					}else bi++, ans += mem[i].b;
				}
			}
		} 
		cout << ans << endl;
	}
	return 0; 
}
//fed5a2e2b397fc303476cd0185c11d65
