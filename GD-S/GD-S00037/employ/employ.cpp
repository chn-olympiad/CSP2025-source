#include<bits/stdc++.h>
using namespace std;
int MOD=998244353;
int n,m;
char a[505];
int c[505];
int zhi[505];
bool pan[505];
long long ans=0;
void dfs(int now){
	if(now>n){
		int num=0;
		for(int i=1;i<=n;++i){
			if(a[i]=='0')++num;
			else if(zhi[i]<=num)++num;
		}
		if(n-num>=m){
			++ans;
			ans%=MOD;
		}
		return;
	}
	for(int i=1;i<=n;++i){
		if(pan[i])continue;
		pan[i]=1;
		zhi[now]=c[i];
		dfs(now+1);
		pan[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int j=1;j<=n;++j){
		cin>>c[j];
	}
	dfs(1);
	cout<<ans;
	return 0;
}
