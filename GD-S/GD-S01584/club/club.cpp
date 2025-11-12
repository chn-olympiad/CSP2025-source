#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N], b[N], c[N];
int s[10], e, n, q, p, l;
int f(){
	int dp[N];
	for (int i = 1; i <= n; i++){
		if(s[1] == e && max(a[i], max(b[i], c[i])) == a[i] && s[2] < (a[i] + max(b[i], c[i]))){
			dp[i] = dp[i - 1] - s[2] + a[i] + s[3];
			if(a[i] < s[2]){
				s[2] = a[i];
			}
			if(a[i] > s[3]){
				s[3] = a[i];
			}
		} else if(s[4] == e && max(a[i], max(b[i], c[i])) == b[i]&& s[5] < (b[i] + max(a[i], c[i]))){
			dp[i] = dp[i - 1] - s[5] + b[i] + s[6];
			if(b[i] < s[5]){
				s[5] = b[i];
			}
			if(b[i] > s[6]){
				s[6] = b[i];
			}
		} else if(s[7] == e && max(a[i], max(b[i], c[i])) == c[i]&& s[8] < (c[i] + max(b[i], a[i]))){
			dp[i] = dp[i - 1] - s[8] + c[i] + s[9];
			if(c[i] < s[8]){
				s[8] = c[i];
			}
			if(c[i] > s[9]){
				s[9] = c[i];
			}
		} else {
			q = max(a[i], max(b[i], c[i]));
			dp[i] = dp[i - 1] + q;
			if(q == a[i]){
				s[1]++;
				p = 2;
				l = 3;
			} else if(q == b[i]){
				s[4]++;
				p = 4;
				l = 5;
			} else{
				s[7]++;
				p = 8;
				l = 9;
			}			
			if(q < s[p]){
				s[p] = a[i];
			}
			if(q > s[l]){
				s[l] = a[i];
			}
		}
	}
	return dp[n];
}
int main(){
	fropen("club.in", r, in);
	fropen("club.out", w, out);
	int t;
	cin >> t;
	for(int i = 1; i <= t; i++){
		cin >> n;
		e = n / 2;
		for(int j = 1; j <= n; j++){
			cin >> a[j] >> b[j] >> c[j];
		}
		s[2] = a[1];
		s[5] = b[1];
		s[8] = c[1];
		cout << f();
	}
	return 0;
} 
