#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+7;
const int mod = 998244353;
int n,ans;
bool kk=true;
int a[N];
int c[N][N];
void dfs(int x,int sum,int maxx,int cnt){
	cnt++;
	if(sum>2*maxx&&cnt>=2){
		ans++;
		ans%=mod;
	}
	for(int i=x+1;i<=n;i++){
		dfs(i,sum+a[i],max(maxx,a[i]),cnt+1);
	}
}
void solve(){
	for(int i=0;i<=n;i++){
		c[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
			c[i][j]%=mod; 
		}
	}
	for(int i=0;i<=n-3;i++){
		ans+=c[n][i];
		ans%=mod;
	}
}
int main(){
	freopen("polygon.in","r",stdin); 
	freopen("polygon.out","w",stdout); 
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1) kk=false;
	}
	if(kk){
		solve();
		cout << ans;
		return 0;
	} 
	for(int i=1;i<=n;i++){
		dfs(i,a[i],a[i],0);
	}
	cout << ans;
	return 0;
}
/*
20
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/
