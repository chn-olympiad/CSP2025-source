#include <bits/stdc++.h> 
using namespace std;

const int Max = 1e5+5; 

int T, n, lim_p, res, ans;
int stf[Max][3];
bool is_in[Max];
int num_p[5];

void xx_dfs(int pos) {
	if (pos == n+1) {
		ans = max(ans,res);
		return;
	}
//	cout << pos << ' ' << res << endl;
	
	if (num_p[1]<lim_p) {
		res += stf[pos][0];
		num_p[1] ++;
//		cout << pos <<"½ø1£¬"<<res<<endl;
		xx_dfs(pos+1);
		num_p[1] --;
		res -= stf[pos][0];
	}
	
	if (num_p[2]<lim_p) {
		res += stf[pos][1];
		num_p[2] ++;
//		cout << pos <<"½ø2£¬"<<res<<endl;
		xx_dfs(pos+1);
		num_p[2] --;
		res -= stf[pos][1];
	}
	
	if (num_p[3]<lim_p) {
		res += stf[pos][2];
		num_p[3] ++;
//		cout << pos <<"½ø3£¬"<<res<<endl;
		xx_dfs(pos+1);
		num_p[3] --;
		res -= stf[pos][2];
	}
}
int main() {
	
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin >> T;
	for (int times=1;times<=T;times++) {
		res=0;
		ans=0;
		
		cin >> n;
		for (int i=1;i<=n;i++) {
			cin >> stf[i][0] >> stf[i][1] >> stf[i][2];
		}
		lim_p=n/2;
		
	xx_dfs(1);
		cout << ans << endl;
	}
	
	return 0;
	
} 
