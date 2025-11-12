#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[510],s1,ret,p,ans;
bool ok[510];
string s;
void dfs(int x){
	if(x==n+1){
//		cout<<ret<<endl;
		ans+=(ret>=m);
		return;
	}
	for(int i=1;i<=n;i++){
		if(ok[i]) continue;
		if(s[x]=='0'){
			ok[i]=1;
			p++;
			dfs(x+1);
			p--;
			ok[i]=0;
			continue;
		}
		ok[i]=1;
		ret+=(c[i]>p);
		int tp=p;
		p+=(c[i]<=p);
		dfs(x+1);
		ok[i]=0;
		p=tp;
		ret-=(c[i]>p);
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;s=' '+s;
	for(int i=1;i<=n;i++) cin>>c[i],s1+=s[i]-'0';
	sort(c+1,c+n+1);
	dfs(1);
	cout<<ans;
	return 0;
}

