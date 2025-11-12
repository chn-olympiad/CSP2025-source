#include<bits/stdc++.h>
#define int long long
using namespace std;
int dp[505][505][505],pre[1000010],c[1000010],vis[1000010],v[1000010],n,m,ans;
string s;
bool check(){
	int sum=0;
	for(int i=1;i<=n;i++){
		if(s[i-1]!='0'&&pre[i]<c[v[i]]){
			sum++;
		}
	}
	if(sum>=m){
		return 1;
	}
	return 0;
}
void dfs(int k){
	if(k==n+1){
		if(check()){
			ans++;
			ans%=998244353;
//			for(int i=1;i<=n;i++){
//				cout<<v[i]<<" ";
//			}
//			cout<<'\n';
		}
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			v[k]=i;
			dfs(k+1);
			vis[i]=0;
		}
	}
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	int ss=s.size();
	for(int i=0;i<ss;i++){
		pre[i+1]=pre[i];
		if(s[i]=='0'){
			pre[i+1]++;
		}
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&c[i]);
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}

