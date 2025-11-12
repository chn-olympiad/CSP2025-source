#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505,mod=998244353;
int n,m,c[N],tmp[N],ans;
string s;
bool vis[N];
void dfs(int now){
	if(now>n){
		int sum=0;
		for(int i=1;i<=n;i++){
			if(sum>=c[tmp[i]]){
				sum++;
				continue;
			}
			if(s[i-1]=='0')
				sum++;
		}
		ans+=(n-sum>=m);
//		for(int i=1;i<=n;i++)
//			cout<<tmp[i]<<' ';
//		cout<<sum<<'\n';
	}
	for(int i=1;i<=n;i++){
		if(!vis[i])
			vis[i]=1,tmp[now]=i,dfs(now+1),vis[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}

