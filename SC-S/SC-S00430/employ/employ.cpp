#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5,mod=998244353;
int n,m,a[N];
string s;
int p[N];

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>m>>s;s=' '+s;
	bool fg1=1;
	for(int i=1;i<=n;i++) fg1&=s[i]=='1';
	if(fg1){
		int ans=1;
		for(int i=1;i<=n;i++) (ans*=i)%=mod;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do{
		int cnt=0;
		for(int i=1;i<=n;i++) if(s[i]=='0'||cnt>=a[p[i]]) cnt++;
		if(n-cnt>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans;
	return 0;
}