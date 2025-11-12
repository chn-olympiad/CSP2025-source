#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5010,mod=998244353;
int n;
int lst[N];
int tot;
pair<int,int>arr[N];
int C[N][N];
int CC(int n,int m){
	if(C[n][m])return C[n][m];
	if(m>n/2)m=n-m;
	if(m==1)return n;
	if(m==0)return 1;
	return(C[n][m]=(CC(n-1,m)+CC(n-1,m-1))%mod);
}
int dfs(int k,int sum,int maxx){
	if(k==tot+1){
		return(sum>2*maxx);
	}
	int cnt=0;
	for(int i=1;i<=arr[k].second;i++)cnt+=(dfs(k+1,sum+i*arr[k].first,max(maxx,arr[k].first))*CC(arr[k].second,i))%mod,cnt%=mod;
	cnt+=dfs(k+1,sum,maxx);
	return(cnt%mod);
}
unordered_map<int,int>mapp;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&lst[i]);
	if(n<=2){
		printf("0");
		return 0;
	}
	for(int i=1;i<=n;i++)mapp[lst[i]]++;
	for(auto k:mapp){
		arr[++tot]=k;
	}
	printf("%lld",dfs(1,0,0));
	return 0;
}
