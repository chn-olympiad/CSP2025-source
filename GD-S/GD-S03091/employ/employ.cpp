#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,c[505],ans;
bool a[505],v[505];
void dfs(int b,int cnt){
	if(cnt==m){
		ll x=1;
		for(int i=1;i<=n-b+1;i++){
			x*=i;
			x%=mod;
		}
		ans+=x;
		ans%=mod;
		return;
	}
	if(b==n+1){
		return;
	}
	for(int i=1;i<=n;i++){
		if(!v[i]){
			v[i]=1;
			if(b-cnt-1<c[i]&&a[b]){
				dfs(b+1,cnt+1);
			}else{
				dfs(b+1,cnt);
			}
			v[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		char x;
		cin>>x;
		x-='0';
		if(x) a[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	return 0;
} 
