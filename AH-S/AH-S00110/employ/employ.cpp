#include<bits/stdc++.h>
#define QAQ cout<<"QAQ";
using namespace std;
typedef long long ll;

const ll MAXN=5e2+5,inf=1e18,mod=998244353;
ll n,m,ans;
string s;
ll a[MAXN],f[MAXN];
void dfs(ll now,ll pre,ll peo){
	if(peo>=m){
		ans++;
	}
	if(now==n+1){
		return ;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			if(pre<a[i]){
				f[i]=1;
				if(s[now-1]=='1'){
					dfs(now+1,pre,peo+1);
				}else{
					dfs(now+1,pre+1,peo);
				}
				f[i]=0;
			}
		}		
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==m){
		int flag=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<0;
		}else{
			ll fff=1;
			for(int i=1;i<=n;i++){
				fff=fff*i%mod;
			}
			cout<<fff;
		}
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
}
