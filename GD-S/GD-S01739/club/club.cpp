#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 4;
int n,a[N][4];
priority_queue<int,vector<int>,greater<int>> q[3];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		int ans = 0;
		for(int i = 1;i <= n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}
		for(int i = 1;i <= n;i++){
			int f1 = 0,f2 = 1,f3 = 2;
			if(a[i][f1] < a[i][f2]) swap(f1,f2);
			if(a[i][f1] < a[i][f3]) swap(f1,f3);
			if(a[i][f2] < a[i][f3]) swap(f2,f3);
			if(q[f1].size() < (unsigned)(n/2)){
				ans += a[i][f1]; q[f1].push(a[i][f1] - a[i][f2]);
			}
			else{
				int r = q[f1].top();
				if(a[i][f2] < a[i][f1] - r){
					ans += a[i][f1] - r;
					q[f1].push(a[i][f1] - a[i][f2]);
					q[f1].pop();
				}
				else{
					ans += a[i][f2];
				}
			}
		}
		cout << ans << "\n";
		for(int i = 0;i < 3;i++){
			while(!q[i].empty()) q[i].pop();
		}
	}
	
	return 0;
} 
