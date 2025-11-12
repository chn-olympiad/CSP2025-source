#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=5010;
int a[N];
int n;
bool vis[N];
int cnt;
int choose;
int sum;
int last;
void dfs(int x,int maxx,int geshu){
	vis[x]=1;
	sum+=a[x];
	if(sum>2*maxx&&geshu>=3){
		cnt++;
	}
	for(int i=x+1;i<=n;i++){
		last=maxx;
		maxx=max(maxx,a[i]);
		++geshu;
		dfs(i,maxx,geshu);
		--geshu;
		maxx=last;
	}
	sum-=a[x];
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(register int i=1;i<=n-2;i++){
		dfs(i,i,1);
		memset(vis,0,sizeof(vis));
	}
	cout<<cnt;
	return 0;
}
