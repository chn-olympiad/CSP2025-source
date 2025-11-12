#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,m;
const int N=510;
int s[N];
int c[N];
int flag=1;
long long A(int n,int k){
	long long sum=1;
	for(int i=1;i<=k;i++) sum=sum*(n-i+1)%Mod;
	return sum;
}
int ans;
bool vis[N];
void dfs(int now,int sum,int loser){
	if(loser+m>n) return ;
	if(now>n){
		if(sum>=m) ans++;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=true;
			if(s[now]==0||c[i]<=loser) dfs(now+1,sum,loser+1);
			else dfs(now+1,sum+1,loser); 
			vis[i]=false;
		}
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	string p;
	cin>>p;
	for(int i=1;i<=n;i++) s[i]=p[i-1]-'0',flag&=p[i-1]-'0';
	for(int i=1;i<=n;i++) cin>>c[i];
	if(flag){
		cout<<A(n,m);
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}

