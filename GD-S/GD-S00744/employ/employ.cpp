#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,p=998244353,c[505],ans;
char s[505];
bool b[505];
void dfs(ll x,ll r){
	if(x>n&&r>=m){
		ans++;
		return;
	}if(r+n+1-x<m)return;
	for(ll i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			if(x-1-r>=c[i])dfs(x+1,r);
			else dfs(x+1,s[x]==49?r+1:r);
			b[i]=0;
		}
	}
}int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	scanf("%s",s+1);
	for(ll i=1;i<=n;i++)scanf("%lld",c+i);
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}
