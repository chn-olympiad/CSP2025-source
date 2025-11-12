#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000005;
int T, n, cnta, cntb, cntc, dp[MAXN];
char q[MAXN];
vector <int> va;
vector <int> vb;
vector <int> vc;

struct P{
	int a, b, c;
	int pos;
}p[MAXN];

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> T;
	while (T--){
		cnta = cntb = cntc = 0;
		va.clear();
		vb.clear();
		vc.clear();
		memset(q, ' ', sizeof(q));
		cin >> n;
		for (int i = 1; i <= n; i++){
			cin >> p[i].a >> p[i].b >> p[i].c;
		}
		for (int i = 1; i <= n; i++){
			if (p[i].a >= p[i].b && p[i].a >= p[i].c){
				if (cnta == (n / 2)){
					int maxn = -INF;
					int k = 0;
					int kv = 0;
					for (int j = 1; j <= n; j++){
						if (q[j] != 'a'){
							continue;
						}
						if (p[j].b > p[j].c){
							if (p[j].b - p[j].a > maxn){
								k = 2;
								kv = j;
								maxn = p[j].b - p[j].a;
							}
						}
						else{
							if (p[j].c - p[j].a > maxn){
								k = 3;
								kv = j;
								maxn = p[j].c - p[j].a;
							}
						}
					}
					if (max(p[i].b, p[i].c) > (maxn + p[i].a)){
						if (p[i].b > p[i].c){
							cntb++;
							q[i] = 'b';
						}
						else{
							cntc++;
							q[i] = 'c';
						}
						dp[i] = dp[i - 1] + max(p[i].b, p[i].c);
					}
					else{
						if (k == 2){
							cntb++;
							q[kv] = 'b';
						}
						else{
							cntc++;
							q[kv] = 'c';
						}
						dp[i] = dp[i - 1] + maxn + p[i].a;
					}
				}
				else{
					dp[i] = dp[i - 1] + p[i].a;
					cnta++;
					q[i] = 'a';
				}
			}
			else if (p[i].b >= p[i].a && p[i].b >= p[i].c){
				if (cntb == n / 2){
					int maxn = -INF;
					int k = 0;
					int kv = 0;
					for (int j = 1; j <= n; j++){
						if (q[j] != 'b'){
							continue;
						}
						if (p[j].a > p[j].c){
							if (p[j].a - p[j].b > maxn){
								k = 1;
								kv = j;
								maxn = p[j].a - p[j].b;
							}
						}
						else{
							if (p[j].c - p[j].b > maxn){
								k = 3;
								kv = j;
								maxn = p[j].c - p[j].b;
							}
						}
					}
					if (max(p[i].a, p[i].c) > maxn + p[i].b){
						if (p[i].a > p[i].c){
							cnta++;
							q[i] = 'a';
						}
						else{
							cntc++;
							q[i] = 'c';
						}
						dp[i] = dp[i - 1] + max(p[i].a, p[i].c);
					}
					else{
						if (k == 1){
							cnta++;
							q[kv] = 'a';
						}
						else{
							cntc++;
							q[kv] = 'c';
						}
						dp[i] = dp[i - 1] + maxn + p[i].b;
					}
				}
				else{
					dp[i] = dp[i - 1] + p[i].b;
					cntb++;
					q[i] = 'b';
				}
			}
			else{
				if (cntc == n / 2){
					int maxn = -INF;
					int k = 0;
					int kv = 0;
					for (int j = 1; j <= n; j++){
						if (q[j] != 'c'){
							continue;
						}
						if (p[j].a > p[j].b){
							if (p[j].a - p[j].c > maxn){
								k = 1;
								kv = j;
								maxn = p[j].a - p[j].c;
							}
						}
						else{
							if (p[j].b - p[j].c > maxn){
								k = 2;
								kv = j;
								maxn = p[j].b - p[j].c;
							}
						}
					}
					if (max(p[i].a, p[i].b) > maxn + p[i].c){
						if (p[i].a > p[i].b){
							cnta++;
							q[i] = 'a';
						}
						else{
							cntb++;
							q[i] = 'b';
						}
						dp[i] = dp[i - 1] + max(p[i].a, p[i].b);
					}
					else{
						if (k == 1){
							cnta++;
							q[kv] = 'a';
						}
						else{
							cntb++;
							q[kv] = 'b';
						}
						dp[i] = dp[i - 1] + maxn + p[i].c;
					}
				}
				else{
					dp[i] = dp[i - 1] + p[i].c;
					cntc++;
					q[i] = 'c';
				}
			}
			
//			cout << "cnta:" << cnta << "=====cntb:"<<cntb<<"=====cntc:"<<cntc<<"\n";
//			cout << dp[i] << "       " << i << endl;
		}
		cout << dp[n] << "\n";
	}
	
	return 0;
}
/*
1
10
2020(1 14533(2 18961(3
2423(1 15344(2 16322(3
1910(1 6224(2 16178(3
2038(1 9963(2 19722(3
8375(2 10557(3 5444(1
3518(1 14615(2 17976(3
6188(1 13424(2 16615(3
8769(2 509(1 4394(3
958(1 3195(2 9953(3
16441(2 5313(1 10926(3


*/
