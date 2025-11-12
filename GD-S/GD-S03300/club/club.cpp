#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<long long, long long>
#define db double;
#define endl "\n"

const int MXN = 1e5+10;
int t,n;
int a[MXN][4];
int dp[MXN][4], mem[MXN][4][4];
struct node{
	int a,b,c;
};
node tmp[MXN];

bool cmp(node a, node b){
	int mxa = max(max(a.a,a.b),a.c);
	int mxb = max(max(b.a,b.b),b.c);
	int sua = a.a+a.b+a.c;
	int sub = b.a+b.b+b.c;
	return (mxa == mxb)? sua > sub : mxa > mxb;
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
		
	cin >> t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(dp,0,sizeof(dp));
		memset(mem,0,sizeof(mem));
		memset(tmp,0,sizeof(tmp));
		
	    cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> a[i][1] >> a[i][2] >> a[i][3];
			tmp[i] = {a[i][1], a[i][2], a[i][3]};
		} 
		
		sort(tmp+1, tmp+n+1, cmp);
		for(int i = 1; i <= n; i++){
			a[i][1] = tmp[i].a;
			a[i][2] = tmp[i].b;
			a[i][3] = tmp[i].c;
		}
		
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				for(int k = 1; k <= 3; k++){
					if(mem[i-1][k][j] < n/2){
						if(dp[i-1][k] + a[i][j] > dp[i][j]){
							dp[i][j] = dp[i-1][k] + a[i][j];
							for(int l = 1; l <= 3; l++){
								mem[i][j][l] = mem[i-1][k][l];
							}
							mem[i][j][j]++;
						}
					}
				}
			}
		}
		
		int ans = 0;
		for(int i = 1; i <= 3; i++){
			ans = max(dp[n][i],ans);
		}
		
		cout << ans << endl;
	}
	
	return 0;
}

