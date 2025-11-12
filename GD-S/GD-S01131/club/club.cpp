#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 10;



signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		if(n == 2){
			int o2[4], o1[4];
			for(int i=1; i<=3; i++){
				cin >> o2[i];
			}
			for(int i=1; i<=3; i++){
				cin >> o1[i];
			}
			int a = o1[1] + o2[2], b = o1[1] + o2[3];
			int c = max(a, max(b, o1[2] + o2[1]));
			int d = max(c, o1[2] + o2[3]);
			int x = o1[3] + o2[1], y = o1[3] + o2[2];
			cout <<max({d, x, y}) <<'\n';
		}
		if(n == 4){
			int o1[10][10], o2[5];
			for(int i=1; i<=4; i++){
				for(int j=1; j<=3; j++){
					cin >> o1[i][j];
				}
			}
			int ans = 0;
			for(int i=0; i<=81; i++){
				int a = i % 3, b = i / 3 % 3, c = i / 9 % 3, d = i / 27 % 3;
				a++;b++;c++;d++;
				o2[1] = o2[2] = o2[3] = 0;
				o2[a]++;o2[b]++;o2[c]++;o2[d]++;
				if(o2[1]>2 ||  o2[2] >2 || o2[3] > 2) continue;
				ans = max(ans, o1[1][a] + o1[2][b] + o1[3][c] + o1[4][d]);
			}
			cout << ans << endl;
		}
		if(n == 10){
			int o1[20][5], o2[15], o3[5];
			for(int i=1; i<=10; i++){
				for(int j=1; j<=3; j++){
					cin >> o1[i][j];
				}
			}
			int ans = 0;//59049
			for(int i=0; i<=59049; i++){
				for(int j=1; j<=3; j++) o3[j] = 0;
				int x = i;
				int sum = 0;
				for(int j=1; j<=10; j++){
					o2[j] = x % 3 + 1;
					x /= 3;
					o3[o2[j]]++;
				}
				bool l = 0;
				for(int j=1; j<=3; j++){
					if(o3[j] > 5){
						l = 1;
						break;
					}
				}
				if(l)continue;
				for(int j=1; j<=10; j++) sum += o1[j][o2[j]];
				ans = max(ans, sum);
			}
			cout << ans << endl;
		}
		
	}
	
	return 0;
}
/*
crossoverºÜÓ´Î÷ 
2
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

1
10
5491 4476 6362
9805 9130 15480
9090 9901 10480
6326 6516 1985
9119 2924 6420
9826 12689 7592
7293 16544 12901
11905 18183 18712
9015 3463 13025
1792 2433 17042

*/
