#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=505,mod=998244353;
int n,m,ans,c[N];
char s[N];
bool A,vis[N];
void dfs(int x,int y){
	if(y>n-m)return;
	if(x>n){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=1;
			if(s[x]=='0'||y>=c[i])
				dfs(x+1,y+1);
			else dfs(x+1,y);
			vis[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++)
		if(s[i]=='0'){
			A=1;break;
		}
	if(!A){
		ans=1;
		for(int i=2;i<=n;i++)
			ans=ans*i%mod;
	}else if(m!=n)dfs(1,0);
	cout<<ans;
	return 0;
}
