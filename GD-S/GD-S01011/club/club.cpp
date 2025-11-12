#include<bits/stdc++.h>
#define int long long
#define N 500005
#define dbg(x) cerr<<#x<<" "<<x<<endl
using namespace std;
int t;
int n;
struct node{
	int a[5], dis;
}peo[N];
void read(){
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= 3; j++){
			cin >> peo[i].a[j];
		}
	}
}
priority_queue<int, vector<int>, greater<int> >q[5];
int mmx(int x[]){
	int t = max(max(x[1], x[2]), x[3]);
	if(x[1] == t) return 1;
	else if(x[2] == t) return 2;
	else return 3;
}
int mnx(int x[]){
	
	int t[5];
	t[1] = x[1], t[2] = x[2], t[3] = x[3];
	sort(t + 1, t + 4);
	if(x[1] == t[2]) return 1;
	else if(x[2] == t[2]) return 2;
	else return 3;
}

void solve(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		peo[i].dis = peo[i].a[mmx(peo[i].a)] - peo[i].a[mnx(peo[i].a)];
		//cout << i << " " << mmx(peo[i].a) << " " << mnx(peo[i].a) << endl;
	}
	
	
	for(int i = 1; i <= n; i++){
		int t = mmx(peo[i].a);
		//dbg(t);
		//dbg(q[t].size());
		//if(q[t].size()) dbg(q[t].top());
		//dbg(peo[i].dis);
		if(q[t].size() == n / 2){
			if(peo[i].dis > q[t].top()){
				ans += peo[i].a[t] - q[t].top();
				q[t].pop();
				q[t].push(peo[i].dis);
			}
			else if(peo[i].dis <= q[t].top()){
				ans += peo[i].a[mnx(peo[i].a)];
				q[mnx(peo[i].a)];
			}
		}
		else{
			ans += peo[i].a[t];
			q[t].push(peo[i].dis);
		}//dbg(ans);
	}//int flag = 1;
//dbg(flag);
	cout << ans << endl;
}
void init(){
	for(int i = 1; i <= 3; i++)
		while(q[i].size()) q[i].pop();
	
}
signed main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		read();
		init();
		solve();
	}
	return 0;
}

