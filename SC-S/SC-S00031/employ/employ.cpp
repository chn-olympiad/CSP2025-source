#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[105];
char c[105];
ll qpl[105];
char zfl[105];
ll jl[105];
ll ans;
bool check(){
	ll tot=0;
	for(int i=1;i<=n;i++){
		if(zfl[i]=='0'){
			for(int j=i+1;j<=n;j++){
				jl[j]++;
			}
		}
		if(jl[i+1]<qpl[i+1]&&zfl[i+1]==0) tot++;
		else{
			for(int j=i+2;j<=n;j++){
				jl[j]++;
			}
		}
	}
	memset(jl,0,sizeof(jl));
	if(tot>=m){
		return true;
	}else{
		return false;
	}
}
bool f[105];
void dfs(int dep){
	if(dep==n+1){
		if(check()){
			ans=(ans+1)%998244353;
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			qpl[dep]=a[i];
			zfl[dep]=c[i];
			dfs(dep+1);
			f[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dfs(1);
	cout<<ans;
	return 0;
}