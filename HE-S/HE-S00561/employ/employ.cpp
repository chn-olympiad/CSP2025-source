#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
const int N=510;
int n,m,ans;
char s[N];
int c[N],cnt;

int p[N];

signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) p[i]=i;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		if(!c[i]) cnt++;
	}
	if(n-cnt<m) {
		cout<<0<<'\n';
		return 0;
	}
//	if(m==1) {
//	ans=1;
//	for(int i=1;i<=n;i++) ans=ans*i%mod;
//	cout<<ans<<'\n';
//	}
	
	do{
		int sum=0;
		for(int i=1;i<=n;i++) {
			if(s[i]=='0'||sum>=c[p[i]]) sum++;
		}
		if(n-sum>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
}
