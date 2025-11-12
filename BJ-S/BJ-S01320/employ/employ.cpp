#include<bits/stdc++.h>
using namespace std;
const int N=500+10;
const int mod=998244353;
int c[N],n,m,a[N],vis[N],ans;
string s;
void dfs(int cur){
	if(cur>n){
		int res=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[a[i]]){
				cnt++;
				continue;
			}
			if(s[i-1]=='0') cnt++;
			else res++;
			if(res>=m){
				ans++;
				ans%=mod;
				break;
			}
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=1;
		a[cur]=i;
		dfs(cur+1);
		vis[i]=0;
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
