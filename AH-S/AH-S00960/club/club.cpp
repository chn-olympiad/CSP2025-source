#include "bits/stdc++.h"
//Eason Cyj001001
#define int long long

using namespace std;
const int N = 1e5 + 10;
int maxn;
int t;
int n;
int a[N][5];
struct f{
	int x,y;
};
bool cmp(f x,f y){
	if(x.x != x.y){
		return x.x > x.y;
	}
	return x.y > y.y;
}
void dfs(int x,int ans1,int ans2,int ans3,int sum) {
    if(x==n+1) {
        maxn = max(maxn,sum);
        return;
    }
    if(ans1 < n/2) {
        dfs(x+1,ans1+1,ans2,ans3,sum+a[x][1]);
    }
    if(ans2 < n/2) {
        dfs(x+1,ans1,ans2+1,ans3,sum+a[x][2]);
    }
    if(ans3 < n/2) {
        dfs(x+1,ans1,ans2,ans3+1,sum+a[x][3]);
    }
    return;
}
struct node{
    int x;
    int ans0,ans1,ans2,ans3;
}dp[N][4]; //在前i个人中的最大满意度值
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    
    cin >> t;
    while(t--) {
		memset(dp,0,sizeof(dp));
		memset(a,0,sizeof(a));
        cin >> n;
        for(int i=1; i<=n; i++) {
            cin >> a[i][1] >> a[i][2] >> a[i][3];
        }
        if(n<=30){
			dfs(1,0,0,0,0);
			cout << maxn;
			continue;
		}
		if(n == 100000) {
			int b[100005];
			memset(b,0,sizeof(b));
			for(int i=1; i<=n; i++){
				b[i] = a[i][1];
			}
			sort(b+1,b+n+1);
			int sum=0;
			for(int i=n; i>=n/2+1; i--){
				sum += b[i];
			}
			f c[100005];
			memset(c,0,sizeof(c));
			for(int i=1; i<=n; i++){
				c[i].x = a[i][1];
				c[i].y = a[i][2];
			}
			sort(c+1,c+n+1,cmp);
			int ansansans = 0;
			for(int i=1; i<=n/2; i++){
				ansansans += c[i].x;
			}
			for(int i=n/2+1; i<=n; i++){
				ansansans += c[i].y;
			}
			cout << max(sum,ansansans) << endl;
			continue;
		}
        //dp[i][1].x = max(dp[i-1][1].x,dp[i-1][2].x,dp[i-1][3].x) + a[i][1];
        for(int i=1; i<=n; i++) {
            int f0,f1,f2,f3;
            f0 = f1 = f2 = f3 = 0;
            f0 = dp[i-1][0].x;
            if(dp[i-1][1].ans1 < n/2) {
                f1 = dp[i-1][1].x;
            }
            if(dp[i-1][2].ans1 < n/2) {
                f2 = dp[i-1][2].x;
            }
            if(dp[i-1][3].ans1 < n/2) {
                f3 = dp[i-1][3].x;
            }
            dp[i][1].x = max(f0,max(f1,max(f2,f3))) + a[i][1];
            if(f1 >= f2 && f1 >= f3) {
				dp[i][1].ans0 = dp[i-1][1].ans0;
                dp[i][1].ans1 = dp[i-1][1].ans1 + 1;
                dp[i][1].ans2 = dp[i-1][1].ans2;
                dp[i][1].ans3 = dp[i-1][1].ans3;
            }else if(f2 >= f1 && f2 >= f3) {
				dp[i][1].ans0 = dp[i-1][2].ans0;
                dp[i][1].ans1 = dp[i-1][2].ans1 + 1;
                dp[i][1].ans2 = dp[i-1][2].ans2;
                dp[i][1].ans3 = dp[i-1][2].ans3;
            }else{
				dp[i][1].ans0 = dp[i-1][3].ans0;
                dp[i][1].ans1 = dp[i-1][3].ans1 + 1;
                dp[i][1].ans2 = dp[i-1][3].ans2;
                dp[i][1].ans3 = dp[i-1][3].ans3;
            }
            dp[i][0].x = max(dp[i][0].x,max(f1,max(f2,f3)));
            //
            f1 = f2 = f3 = 0;
            if(dp[i-1][1].ans2 < n/2) {
                f1 = dp[i-1][1].x;
            }
            if(dp[i-1][2].ans2 < n/2) {
                f2 = dp[i-1][2].x;
            }
            if(dp[i-1][3].ans2 < n/2) {
                f3 = dp[i-1][3].x;
            }
            dp[i][2].x = max(f0,max(f1,max(f2,f3))) + a[i][2];
            if(f1 >= f2 && f1 >= f3) {
				dp[i][2].ans0 = dp[i-1][1].ans0;
                dp[i][2].ans1 = dp[i-1][1].ans1;
                dp[i][2].ans2 = dp[i-1][1].ans2 + 1;
                dp[i][2].ans3 = dp[i-1][1].ans3;
            }else if(f2 >= f1 && f2 >= f3) {
				dp[i][2].ans0 = dp[i-1][2].ans0;
                dp[i][2].ans1 = dp[i-1][2].ans1;
                dp[i][2].ans2 = dp[i-1][2].ans2 + 1;
                dp[i][2].ans3 = dp[i-1][2].ans3;
            }else{
				dp[i][2].ans0 = dp[i-1][3].ans0;
                dp[i][2].ans1 = dp[i-1][3].ans1;
                dp[i][2].ans2 = dp[i-1][3].ans2 + 1;
                dp[i][2].ans3 = dp[i-1][3].ans3;
            }
            dp[i][0].x = max(dp[i][0].x,max(f1,max(f2,f3)));
            //
            f1 = f2 = f3 = 0;
            if(dp[i-1][1].ans3 < n/2) {
                f1 = dp[i-1][1].x;
            }
            if(dp[i-1][2].ans3 < n/2) {
                f2 = dp[i-1][2].x;
            }
            if(dp[i-1][3].ans3 < n/2) {
                f3 = dp[i-1][3].x;
            }
            dp[i][3].x = max(f0,max(f1,max(f2,f3))) + a[i][3];
            if(f1 >= f2 && f1 >= f3) {
				dp[i][3].ans0 = dp[i-1][1].ans0;
                dp[i][3].ans1 = dp[i-1][1].ans1;
                dp[i][3].ans2 = dp[i-1][1].ans2;
                dp[i][3].ans3 = dp[i-1][1].ans3 + 1;
            }else if(f2 >= f1 && f2 >= f3) {
				dp[i][3].ans0 = dp[i-1][2].ans0;
                dp[i][3].ans1 = dp[i-1][2].ans1;
                dp[i][3].ans2 = dp[i-1][2].ans2;
                dp[i][3].ans3 = dp[i-1][2].ans3 + 1;
            }else{
				dp[i][3].ans0 = dp[i-1][3].ans0;
                dp[i][3].ans1 = dp[i-1][3].ans1;
                dp[i][3].ans2 = dp[i-1][3].ans2;
                dp[i][3].ans3 = dp[i-1][3].ans3 + 1;
            }
            dp[i][0].x = max(dp[i][0].x,max(f1,max(f2,f3)));
           // for(int j=1; j<=3; j++){
			//	cout << i << " " << j << " " << dp[i][j].x << " " << dp[i][j].ans1 << " " << dp[i][j].ans2 << " " << dp[i][j].ans3 << " " << endl;
			//}
        }
        cout << max(dp[n][1].x,max(dp[n][2].x,dp[n][3].x)) << endl;
    }
    return 0;
}
