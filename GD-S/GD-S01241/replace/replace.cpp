#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
string s1[maxn] , s2[maxn] , t1[maxn] , t2[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	int n , q;
	cin >> n >> q;
	for(int i = 1 ; i <= n ; i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i = 1 ; i <= q ; i++){
		cin >> t1[i] >> t2[i];
		int cnt = 0;
		t1[i + 1] = t1[i];
		for(int j = 1 ; j <= n ; j++){
			t1[i] = t1[i + 1];
			int g = t1[i].find(s1[j]);
//			cout << g << '\n';
			if(g != -1){
				for(int x = g ; x < g + s1[j].size() ; x++){
					t1[i][x] = s2[j][x - g];
				}
//				cout << t1[i] << ' ' << t2[i] << '\n';
				if(t1[i] == t2[i]){
					++cnt;
				}
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
