#include<bits/stdc++.h>
using namespace std;
const int MAXN=5005,MOD=998244353;
int n,a[MAXN],mx;
long long pw[MAXN],C[MAXN][MAXN],ans;
void sC(){  //组合 
	pw[0]=1;  //阶乘 
	for (int i=1;i<=n;i++){  //i个中取j个
		pw[i]=(pw[i-1]*i)%MOD;
		for (int j=1;j<=i;j++){
			C[i][j]=((pw[i]/pw[i-j]/pw[j])%MOD);
		}
	}
}
bool used[MAXN];
void dfs(int cnt,long long sum,int mxi){
	if (cnt>=3 and sum>a[mxi]){
		ans++;
		ans=ans%MOD;
	}
	for (int i=1;i<mxi;i++){
		if (used[i]==0){
			used[i]=1;
			dfs(cnt+1,sum+a[i],mxi);
			used[i]=0;
		}
	}
}
int main(){
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	if (n<3){
		cout<<0;
		return 0;
	}
	if (n==3){
		if (a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	if (mx==1){
		sC();
		for (int i=3;i<=n;i++){
			ans=(ans+C[n][i])%MOD;
		}
		cout<<ans%MOD;
		return 0;
	}
	for (int i=1;i<=n;i++){
		dfs(1,0,i);
	}
	cout<<ans%MOD;
	return 0;
}

// give me 50pts plsplspls...QAQ
