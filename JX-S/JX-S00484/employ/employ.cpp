#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int P=998244353;
const int N=505;
int n,m,c[N];
string s;
int a[N],sum[N];
bool book[N];
ll f[N],ans;
void dfs(int step,int sum){
	if (step>n&&sum>=m) {
		ans++;
		return ;
	}
	if (step>n) return;
	if (sum>=m){
		ans=(f[n-step+1]+ans)%P;
		return;
	}
	for (int i=1;i<=n;i++){
		if (book[i]) continue;
		book[i]=1;
		if (c[i]<step-sum)
			dfs(step+1,sum);
		else {
			switch (s[step-1]){
				case '1':
					dfs(step+1,sum+1);
					break;
				case '0':
					dfs(step+1,sum);
					break;
			}
		}
		book[i]=0;
	 }
}
int dp[N][N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	f[0]=1;
	for (int i=1;i<=n;i++)
		f[i]=f[i-1]*i%P;
	for (int i=1;i<=n;i++)
		cin>>c[i],sum[c[i]]++;
	bitset<N> tmp(s);
	if ((int)tmp.count()==n)
		cout<<f[n];
	else if ((int)tmp.count()<m)
		cout<<'0';
	else if (n<=20){
		dfs(1,0);
		cout<<ans;
	}
	else {
		dp[0][0]=1;
		for (int i=1;i<=n;i++){
			for (int j=0;j<=i;j++){
				for (int k=1;k<=n;k++){
					dp[i][j]=(dp[i-1][j-1]+dp[i][j-1])%P;
				}
			}
		}
	}
	return 0;
}
