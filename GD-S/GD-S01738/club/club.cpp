#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e5+5;
int n,x[4][maxn],ans=-1;
//If S T1 is DP then AFO so......
//dp[x][a][b]means goto x and 1 got a 2 got b
//we do not need to use the first dimension
//Let's have a try
//oh no Memory is exploded
//so mabey it's not DP
//x[i][j] <= 2e4?
//perhaps it's only tell us we do not need to use long long
//actually if dp 1e5 means we only have to use one dimensions
//or it's adhoc?bruh,I hate it,ant of it(DP or adhoc)
//how many is 3^30?
//oh no
//we have only 20 pts
//help¡­¡­ 
//long long cal(){
//	long long ans=1;
//	for(int i=1;i<=15;i++)ans*=3;
//	return ans;
//}
//wait¡­¡­perhaps zhuangya?
//3jinzhe 3^(1e5) exploded yet again
//yeah,zhuangya is just equals to dfs 
//special A is ez we got 25pts now
//Why is T1 so hard?
//1h just past......
//HELP!!
//godblessmepls!!!
//ther's a fact that if one of them is full,no one other will be full
//is that any use?
//2h passed and T1 is still unACable!
bool A=1,B=1;
void dfs(int i,int sum,int a,int b){
	if(i==n+1){
		ans=max(ans,sum);
		return;
	}
	if(a<n/2)dfs(i+1,sum+x[1][i],a+1,b);
	if(b<n/2)dfs(i+1,sum+x[2][i],a,b+1);
	if(i-a-b-1<n/2)dfs(i+1,sum+x[3][i],a,b);
}
void solve(){
	ans=-1;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>x[j][i];
		}
		A&=(x[2][i]==0);
		B&=(x[3][i]==0);
	}
	A&=B;
	if(A){
		sort(x[1]+1,x[1]+n+1);
		int ans=0;
		for(int i=n;i>=n-n/2+1;i--){
			ans+=x[1][i];
		}cout<<ans<<'\n';
		return;
	}
	dfs(1,0,0,0);
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	return 0;
}
//40 min left
//for god's sake¡­¡­ 
