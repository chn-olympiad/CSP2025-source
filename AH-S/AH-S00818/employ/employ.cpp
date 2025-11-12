#include<bits/stdc++.h>
using namespace std;
const int N=20,Mod=998244353;
bool st;
int a[N],f[1<<N][N],n,m,t[N],q[N],p[N];
int dfs(int step,int x){
	if(n-x<m)
		return 0;
	if(step==n+1){
		if(n-x>=m)
			return 1;
		return 0;
	}
	int mark=0;
	for(int i=1;i<=n;i++)
		mark=mark*2+q[i];
	if(f[mark][x])
		return f[mark][x];
	int ans=0;
	for(int i=1;i<=n;i++){
		if(q[i])
			continue;
		p[step]=i;
		q[i]=1;
		if(t[step]==0||x>=a[i])
			ans+=dfs(step+1,x+1);
		else
			ans+=dfs(step+1,x);
		ans%=Mod;
		q[i]=0;
	}
	return f[mark][x]=ans%Mod;
}
bool ed;
void solve(){
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
		t[i+1]=s[i]-'0';
	for(int i=1;i<=n;i++)
		cin>>a[i];
	cout<<dfs(1,0)<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int t=1;
	while(t--)
		solve();
	return 0;
}
//my luogu uid is 1115541
//my luogu name is dong0717
//可以给个关注吗喵