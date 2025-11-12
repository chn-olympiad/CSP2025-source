#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6+10;
int a[N][4];
bool b[N][4];
int num[4];
int n,t,ans;
void dfs(int step,int sum){
	//cout << step << ":" << sum << endl;
	if(step==n+1){
		ans = max(ans,sum);
		return;
	}
	for(int j=1;j<=3;j++){
			if(b[step][j]==false&&num[j]<n/2){
				b[step][j] = true;
				num[j]++;
				dfs(step+1,sum+a[step][j]);
				num[j]--;
				b[step][j] = false;
		}
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	for(int i=1;i<=t;i++){
		cin >> n;
		memset(a,0,sizeof a);
		ans = 0;
		for(int i=1;i<=n;i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
		dfs(1,0);
		cout << ans << endl;
	}
	return 0;
}//love you ccf
