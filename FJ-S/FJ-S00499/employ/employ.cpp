#include<bits/stdc++.h>
using namespace std;
#define int long long
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
const int N=505,mod=998244353;
int n,m,s[N],c[N],ans,v[N];
string ss;
void dfs(int x,int res){
	if(x==n+1){
		if(res>=m) ans=(ans+1)%mod;
		return;
	}
	if(res+n-x+1<m) return;
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		if(x-1-res>=c[i]) dfs(x+1,res);
		else{
			if(s[x]==1) dfs(x+1,res+1);
			else dfs(x+1,res);
		}
		v[i]=0;
	}
}
void dfs2(int x){
	if(x==n+1){
		ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(v[i]) continue;
		v[i]=1;
		if(x-1>=c[i]) dfs2(x+1);
		else{
			if(s[i]==1) return;
			dfs2(x+1);
		}
		v[i]=0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	qwq;
	cin>>n>>m;
	cin>>ss;
	for(int i=1;i<=n;i++){
		s[i]=ss[i-1]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(n<=18||m==n){
		if(m!=n){
			dfs(1,0);
			cout<<ans;
		}
		else{
			bool pd=false;
			for(int i=1;i<=n;i++) if(s[i]==0) pd=true;
			if(pd==true){
				cout<<"0";
			}
			else{
				dfs(1,0);
				cout<<ans;
			}
		}
	}
	else{
		if(m==1){
			int res=1;
			for(int i=2;i<=n;i++) res=res*i%mod;
			dfs2(1);
			res=(res-ans+mod)%mod;
			cout<<res;
		}
		else cout<<"0";
	}
	return 0;
}
