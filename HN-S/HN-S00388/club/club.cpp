#include<bits/stdc++.h>
using namespace std;
int s[100001][4], a[100001], b[100001], c[100001];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--){
		int n, A = 0, B = 0, C = 0;
		long long num = 0;
		scanf("%d", &n);
		int mn = n / 2;
		for(int i = 1; i <= n; i++){
			scanf("%d%d%d", &s[i][1], &s[i][2], &s[i][3]);
			if(s[i][1] >= s[i][2] && s[i][1] >= s[i][3]){
				A++;
				num += s[i][1];
				a[A] = min(abs(s[i][1] - s[i][2]), abs(s[i][1] - s[i][3]));
			}else if(s[i][2] >= s[i][1] && s[i][2] >= s[i][3]){
				B++;
				num += s[i][2];
				b[B] = min(abs(s[i][1] - s[i][2]), abs(s[i][2] - s[i][3]));
			}else{
				C++;
				num += s[i][3];
				c[C] = min(abs(s[i][3] - s[i][2]), abs(s[i][1] - s[i][3]));
			}
		}
		if(C > mn){
			sort(c+1, c+C+1);
			for(int i = 1; i <= C-mn; i++){
				num -= c[i];
			}
		}else if(B > mn){
			sort(b+1, b+B+1);
			for(int i = 1; i <= B-mn; i++){
				num -= b[i];
			}
		}else if(A > mn){
			sort(a+1, a+A+1);
			for(int i = 1; i <= A-mn; i++){
				num -= a[i];
			}
		}
		cout << num << endl;
	}
	return 0;
}
