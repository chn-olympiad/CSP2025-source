#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int mod=998244353;
int n,m,c[505],l,s=1,f[505],ans,flag1=1,flag2=1;
string str;

void dfs(int u,int num,int k){
	f[u]=1;
	if(num+k==n && num>=m){
		ans=(ans+1)%mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		if(c[i]>k && str[num+k]!='0') dfs(i,num+1,k);
		else dfs(i,num,k+1);
		f[i]=0;
	}
	return;
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> str;
	l=str.size();
	for(int i=1;i<=n;i++) cin >> c[i],flag1=(c[i]!=0),s=s*i%mod;
	for(int i=0;i<l;i++)
		if(str[i]!='1') flag2=0;
	if(flag2 && m==n){
		if(flag1) cout << s;
		else cout << 0;
		return 0;
	}
	dfs(0,0,0);
	cout << ans;
	return 0;
}
