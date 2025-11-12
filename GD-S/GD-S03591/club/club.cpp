#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; i++)
#define ll long long
const int N = 1e5+2;
int T,n,t[4],a[N][4],f[N];
ll ans;
void dfs(int s, ll cost){
	if(s == n+1){
		ans = max(ans,cost);
		return;
	}
	if(t[1] < (n>>1)){
		int t1 = t[1];
		t[1]++;
		dfs(s+1,cost+a[s][1]);
		t[1] = t1;
	}
	if(t[2] < (n>>1)){
		int t2 = t[2];
		t[2]++;
		dfs(s+1,cost+a[s][2]);
		t[2] = t2;
	}
	if(t[3] < (n>>1)){
		int t3 = t[3];
		t[3]++;
		dfs(s+1,cost+a[s][3]);
		t[3]= t3;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> T;
	while(T--){
		cin >> n;
		FOR(i,1,n){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
		}
		ans = 0;
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}
