#include<bits/stdc++.h>
#define endl '\n'
#define PII pair<int,int>
#define qaq cin.tie(0)->ios::sync_with_stdio(0)
using namespace std;
typedef long long ll;
const int N = 205;
int n;
ll a[N],b[N],c[N];
ll dp[N/2][N/2][N/2];
ll ru[100005];
ll dfs(int p,int k,int w){
	if(p+k+w==n){
		return 0;
	}
	int cnt=p+k+w+1;
	if(dp[p][k][w]){
		return dp[p][k][w];
	}
	ll ans=0;
	if(p+1<=n/2){
		ans = max(ans,dfs(p+1,k,w)+a[cnt]);
	}
	if(k+1<=n/2){
		ans = max(ans,dfs(p,k+1,w)+b[cnt]);
	}
	if(w+1<=n/2){
		ans = max(ans,dfs(p,k,w+1)+c[cnt]);
	}
	dp[p][k][w] = ans;
	return ans;
}
ll kkk(int cnt){
	if(cnt==n+1){
		return 0;
	}
	ll ans=kkk(cnt+1);
	if(cnt+1<=n/2){
		ans = max(ans,kkk(cnt+1)+a[cnt]);
	}
	ru[cnt]=ans;
	return ans;
}
inline void solve(){
	memset(dp,0,sizeof dp);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> b[i] >> c[i];
	} 
	if(n<=464){
		memset(dp,0,sizeof dp);
		cout << dfs(0,0,0) << endl;
	}
	else {
		memset(ru,0,sizeof ru);
		cout << kkk(1);
	}
}
int main(){
	qaq;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin >> T;
	while(T--)solve();
	return 0;
}
 




