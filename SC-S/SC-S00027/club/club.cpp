#include <bits/stdc++.h>
using namespace std;
int t,n;
struct ss{
	int x,y,z;
}a[100005];
long long dp[35][35][35];
int pos1[100005],pos2[100005];
long long ans;
int vis[100005];
bool check(){
	for(int i=1; i<=n; i++){
		if(a[i].y||a[i].z) return 0;
	}
	return 1;
}
bool check1(){
	for(int i=1; i<=n; i++){
		if(a[i].z) return 0;
	}
	return 1;
}
bool cmp1(ss x,ss y){
	return x.x > y.x;
}
bool cmp2(int x,int y){
	return abs(a[x].x-a[x].y)<abs(a[y].x-a[y].y);
}
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q1;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q2;
int main(){
	//70pts
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		ans = 0;
		memset(dp,0,sizeof(dp));
		cin >> n;
		for(int i=1; i<=n; i++){
			a[i].x = a[i].y = a[i].z = 0;
			cin >> a[i].x >> a[i].y >> a[i].z;
		}
		if(n<=30){
			for(int i=1; i<=n; i++){
				for(int j=min(n/2,i-1); j>=0; j--){
					for(int k=min(n/2,i-1); k>=0; k--){
						for(int kk=min(n/2,i-1); kk>=0; kk--){
							if(j+k+kk>=n) continue;
							dp[j+1][k][kk] = max(dp[j+1][k][kk],dp[j][k][kk]+a[i].x);
							dp[j][k+1][kk] = max(dp[j][k+1][kk],dp[j][k][kk]+a[i].y);
							dp[j][k][kk+1] = max(dp[j][k][kk+1],dp[j][k][kk]+a[i].z);
						}
					}
				}
			}
			for(int i=0; i<=n/2; i++){
				for(int j=0; j<=n/2; j++){
					for(int k=0; k<=n/2; k++){
						if(i+j+k!=n) continue;
						ans = max(ans,dp[i][j][k]);
					}
				}
			}
			cout << ans << '\n';
		}else if(check()){
			sort(a+1,a+1+n,cmp1);
			for(int i=1; i<=n/2; i++){
				ans += a[i].x;
			}
			cout << ans << '\n';
		}else if(check1()){
			int cnt1 = 0,cnt2 = 0;
			for(int i=1; i<=n; i++){
				if(a[i].x>a[i].y){
					pos1[++cnt1] = i;
				}else{
					pos2[++cnt2] = i;
				}
				ans += max(a[i].x,a[i].y);
			}
			if(cnt1>n/2){
				sort(pos1+1,pos1+1+cnt1,cmp2);
				for(int i=1; i<=cnt1-n/2; i++){
					ans -= abs(a[pos1[i]].x-a[pos1[i]].y);
				}
			}else if(cnt2>n/2){
				sort(pos2+1,pos2+1+cnt2,cmp2);
				for(int i=1; i<=cnt2-n/2; i++){
					ans -= abs(a[pos2[i]].x-a[pos2[i]].y);
				}
			}
			cout << ans << '\n';
		}else{
			for(int i=1; i<=n; i++){
				ans += max(a[i].x,max(a[i].y,a[i].z));
			}
			cout << ans << '\n';
		}
	}
	return 0;
} 