#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e2+10;
const int mod = 998244353;
int n,m,a[N],b[N],c[N],ans;
string s;
void dfs(int x){
	if(x>n){
		int cnt=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='0'){
				++cnt;
				continue;
			}
			if(cnt>=c[a[i]]){
				++cnt;
				continue;
			}
		}
		if(n-cnt>=m) ++ans;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;++i){
		if(!b[i]){
			b[i]=1;
			a[x]=i;
			dfs(x+1);
			a[x]=0;
			b[i]=0;
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;++i) cin>>c[i];
	dfs(1);
	cout<<ans;
	return 0;
}
