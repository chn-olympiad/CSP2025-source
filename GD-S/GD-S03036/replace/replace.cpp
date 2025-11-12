#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200010;
int n, q;
string s[N][2], t1, t2;
queue<pair<string, LL>> qu;
int main(){
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++){
		cin >> s[i][0] >> s[i][1];
	}
	while(q--){
		cin >> t1 >> t2;
		LL res = 0;
//		qu.push({t1, 0});
//		while(!qu.empty()){
//			auto t = qu.front();
//			qu.pop();
//			for(int i = 1;i <= n;i++){
//				if(t.first.found(s[i][0]) != t.first.size());
//			}
//		}
		printf("%lld\n", res);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
