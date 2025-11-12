#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int M=998244353;
ll n,m,s[505],a[505],f[505],p[505];
char c;
ll dfs(ll st){
	ll ans=0;
	if(st>n){
		ll ls=0,ans=0;
		for(int i=1;i<=n;i++){
			if(ls>=a[p[i]]||!s[i]) ls++;
			else ans++;
		}
		return ans>=m;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		p[st]=i;
		ans+=dfs(st+1);
		ans%=M;
		f[i]=0;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		s[i]=c-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<dfs(1);
	return 0;
}
