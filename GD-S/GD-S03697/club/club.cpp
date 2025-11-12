#include <bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;
int a[100010][5];
int c[100010][5][5];
int f[100010][5];
priority_queue<int> q[5];
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		memset(f, 0, sizeof(f));
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
        int q1 = 0, q2 = 0, q0 = 0;
		for (int i = 0; i < n; i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			c[i][0][1] = abs(a[i][0] - a[i][1]);
			c[i][1][0] = abs(a[i][0] - a[i][1]);
			c[i][2][0] = abs(a[i][0] - a[i][2]);
			c[i][0][2] = abs(a[i][0] - a[i][2]);
			c[i][2][1] = abs(a[i][1] - a[i][2]);
			c[i][1][2] = abs(a[i][1] - a[i][2]);
		}
		int ret = 0;
		for (int i = 0; i < n; i++){
			if (a[i][0] >= a[i][1] && a[i][0] >= a[i][2]){
				q[0].push(-min(c[i][0][1], c[i][0][2]));
				ret += a[i][0];
				q0++;
			}
			if (a[i][1] >= a[i][0] && a[i][1] >= a[i][2]){
				q[1].push(-min(c[i][1][0], c[i][1][2]));
				ret += a[i][1];
				q1++;
			}
			if (a[i][2] >= a[i][0] && a[i][2] >= a[i][1]){
				q[2].push(-min(c[i][2][0], c[i][2][1]));
				ret += a[i][2];
				q2++;
			}
		}
		if (q0 > n / 2){
			while(q0 > n / 2){
				ret += q[0].top();
				q[0].pop();
				q0--;
			}
		}
		if (q1 > n / 2){
			while(q1 > n / 2){
				
				ret += q[1].top();
				q[1].pop();
				q1--;
			}
		}
		if (q2 > n / 2){
			while(q2 > n / 2){
				ret += q[2].top();
				q[2].pop();
				q2--;
			}
		}
		while(!q[0].empty()) q[0].pop();
		
		while(!q[1].empty()) q[1].pop();
		
		while(!q[2].empty()) q[2].pop();
		
		cout << ret << endl; 
	}
}
