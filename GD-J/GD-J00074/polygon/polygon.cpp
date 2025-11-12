#include <bits/stdc++.h>
using namespace std;
const int MAXN=5005;
int n;
long long a[MAXN];
long long ans=0;
bool vis[MAXN];
void check();
void dfs(long long now);
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	dfs(1);
	cout<<ans%998244353;
	fclose(stdout);
	fclose(stdout);
	return 0;
}
void dfs(long long now){
	if(now==n+1){
		check();
		return;
	} 
	vis[now]=1;
	dfs(now+1);
	vis[now]=0;
	dfs(now+1);
}
void check(){
	long long sum1=0,sum2=0,maxx=0;
	for(int i=1;i<=n;i++){
		if(vis[i]){
			sum1+=1;
			sum2+=a[i];
			maxx=max(maxx,a[i]);
		}
	}
	if(sum1>=3 && sum2>maxx*2) ans++;
}
