#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 5;
int a[N][4];
int n,ans;
int x[N];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--){
		ans = 0;
		priority_queue<int,vector<int>,greater<int>>q;
		cin >> n;
		int t1 = 0,t2 = 0,t3 = 0;
		for(int i = 1;i <= n;i++){;
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			int maxx = max(a[i][1],max(a[i][2],a[i][3]));
			ans += maxx;
			if(maxx == a[i][1]){
				x[i] = 1;
				t1++;
			}else if(maxx == a[i][2]){
				x[i] = 2;
				t2++; 
			}else{
				x[i] = 3;
				t3++;
			}
		}
		if(t1 > n / 2){
			for(int i = 1;i <= n;i++){
				if(x[i] == 1){
					q.push(min(a[i][1] - a[i][2],a[i][1] - a[i][3])); 
				}
			}
			while(t1 > n / 2){
				t1--;
				ans -= q.top();
				q.pop();
			}
		}else if(t2 > n / 2){
			for(int i = 1;i <= n;i++){
				if(x[i] == 2){
					q.push(min(a[i][2] - a[i][1],a[i][2] - a[i][3])); 
				}
			}
			while(t2 > n / 2){
				t2--;
				ans -= q.top();
				q.pop();
			}
		}else if(t3 > n / 2){
			for(int i = 1;i <= n;i++){
				if(x[i] == 3){
					q.push(min(a[i][3] - a[i][1],a[i][3] - a[i][2])); 
				}
			}
			while(t3 > n / 2){
				t3--;
				ans -= q.top();
				q.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
} 