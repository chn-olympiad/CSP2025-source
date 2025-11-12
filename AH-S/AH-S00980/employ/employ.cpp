#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=998244353;
int n,m,c[505],a[505];
ll ans;
string s;
bool flag=true,vis[505];
ll dfs(int idx,int bt){
	ll tmp=0;
	if(n-bt<m)
		return 0;
	if(idx==n+1)
		return 1;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(bt<c[i]&&s[idx]=='1')
				tmp=(tmp+dfs(idx+1,bt))%N;
			else
				tmp=(tmp+dfs(idx+1,bt+1))%N;
			vis[i]=0;
		}
	return tmp;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	ans=dfs(1,0);
	cout<<ans;
	return 0;
}
