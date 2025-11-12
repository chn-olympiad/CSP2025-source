#include<iostream>
using namespace std;
#define M 998244353
int n, m, ans=0, b[514], vis[514];
string s;
void dfs(int k, int t){
	if(k==n){
		if(t>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++)if(!vis[i]){
		vis[i]=1;
		dfs(k+1, t+(s[k]=='1'&&b[i]>k-t));
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	scanf("%d%d", &n, &m);
	cin >> s;
	for(int i=1;i<=n;i++)scanf("%d", &b[i]);
	bool bo=1;
	for(int i=1;i<=n;i++)if(!b[i]){
		bo=0;
		break;
	}
	if(bo){
		long long sum=1;
		for(int i=1;i<=n;i++)sum=sum*i%M;
		printf("%lld", sum);
	}else{
		dfs(0, 0);
		printf("%d", ans);
	}
	return 0;
}
