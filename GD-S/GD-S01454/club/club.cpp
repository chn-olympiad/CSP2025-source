#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e5 + 5;
int n , t;
int mid;
int ans;
int a[N][4];
bool vis[N][4];
int maxn1[N] , maxn2[N] , id1[N] , id2[N];
priority_queue<int , vector<int> , greater<int> >q[4];
void init(){
	memset(maxn1 , 0 , sizeof(maxn1));
	memset(maxn2 , 0 , sizeof(maxn2));
	memset(id2 , 0 , sizeof(id2));
	memset(id1 , 0 , sizeof(id1));
	memset(vis , 0 , sizeof(vis));
	ans = 0;
	for(int i = 1 ;i <= 3 ;i++){
		while(!q[i].empty()){
			q[i].pop();
		}
	}
}
signed main(){
	freopen("club.in" , "r" , stdin);
	freopen("club.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0) , cout.tie(0);
	cin >> t;
	while(t--){
		init();
		cin >> n;
		mid = n / 2;
		for(int i = 1 ;i <= n ;i++){
			for(int j = 1 ;j <= 3 ;j++){
				cin >> a[i][j];
			}
		}
		for(int i = 1 ;i <= n ;i++){
			for(int j = 1 ;j <= 3 ;j++){
				if(maxn1[i] < a[i][j]){
					maxn1[i] = a[i][j];
					id1[i] = j;
				}
			}
			ans += maxn1[i];
			vis[i][id1[i]] = 1;
		}
		for(int i = 1 ;i <= n ;i++){
			for(int j = 1 ;j <= 3 ;j++){
				if(maxn2[i] < a[i][j] && !vis[i][j]){
					maxn2[i] = a[i][j];
					id2[i] = j;			
				}
			}
		}
		for(int i = 1 ;i <= n ;i++){
			q[id1[i]].push(maxn1[i] - maxn2[i]);
		}
		for(int i = 1 ;i <= 3 ;i++){
			while(q[i].size() > mid){
				ans -= q[i].top();
				q[i].pop();
			}
		}
		cout << ans << endl;		
	}
	return 0;
}
