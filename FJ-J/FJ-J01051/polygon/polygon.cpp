#include<bits/stdc++.h>
using namespace std;

const long long MOD=998244353,N=3005;

int n,a[N],dp[N][N],vis[N],ans;
bool all1=1;

int ipow(int a,int b){
	int ans=1;
	for(int i=1;i<=b;i++){
		ans*=a;
		ans%=MOD;
	}
	return ans;
}

bool check(int len){
	int maxx=0,sum=0;
	for(int i=1;i<len;i++){
		maxx=max(maxx,vis[i]);
		sum+=vis[i];
	}
	return sum>maxx*2;
}

void dfs(int k,int p){
	if(k==n&&check(p)){
		ans++;
		ans%=MOD;
		return;
	}
	for(int i=k;i<=n;i++){
		vis[p]=a[i];
		dfs(i+1,p+1);
		vis[p]=0;
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) all1=0;
	}
	if(all1) cout<<ipow(2,n);
	else{
		dfs(1,1);
		cout<<ans;
	}
	return 0;
}
