#include<bits/stdc++.h>
#define int long long
#define rint register int
using namespace std;
const int N=5e3+5,Mod=998244353;
int n,a[N];
inline int dfs(const rint& dep,const rint& mx,const rint& sum,const rint& k){
	if(dep==n+1){
		if(k<3) return 0;
		if((mx<<1)>=sum) return 0;
		return 1;
	}
	return (dfs(dep+1,mx,sum,k)+dfs(dep+1,max(mx,a[dep]),sum+a[dep],k+1))%Mod;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(rint i=1;i<=n;++i)
		cin>>a[i];
	cout<<dfs(1,-1,0,0)%Mod;
	return 0;
}

