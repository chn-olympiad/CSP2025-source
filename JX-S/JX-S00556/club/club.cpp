#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 1e5+5;
int T;
int n;
int a[N][4];
int read(){
	int res = 0;
	char ch = getchar();
	while(!(ch >= '0' && ch <= '9')) ch = getchar();
	while(ch >= '0' && ch <= '9'){
		res = res*10+ch-'0';
		ch = getchar();
	}
	return res;
}
priority_queue<int, vector<int>, greater<int>> Q1, Q2, Q3;
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	T = read();
	while(T--){
		long long ans = 0;
		n = read();
		for(int i = 1; i <= n; i++) a[i][1] = read(), a[i][2] = read(), a[i][3] = read();
		
		while(Q1.size()) Q1.pop();
		while(Q2.size()) Q2.pop();
		while(Q3.size()) Q3.pop();
		
		for(int i = 1; i <= n; i++){
			int p = 1;
			int fir = 0, sec = 0;
			for(int j = 1; j <= 3; j++){
				if(a[i][j] > fir){
					p = j;
					sec = fir;
					fir = a[i][j];
				}else if(a[i][j] > sec) sec = a[i][j];
			}
			ans += fir;
			switch(p){
				case 1:
					Q1.push(fir-sec);
					break;
				case 2:
					Q2.push(fir-sec);
					break;
				case 3:
					Q3.push(fir-sec);
					break;
			}
		}
		
		while((int)Q1.size() > n/2) ans -= Q1.top(), Q1.pop();
		while((int)Q2.size() > n/2) ans -= Q2.top(), Q2.pop();
		while((int)Q3.size() > n/2) ans -= Q3.top(), Q3.pop();
		
		printf("%lld\n", ans);
	}
	return 0;
}
