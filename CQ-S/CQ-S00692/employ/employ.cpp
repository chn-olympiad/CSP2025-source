#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
const int mod=998244353;
inline void Freopen(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
}
int n,m;
char s[MAXN]; int c[MAXN],p[MAXN],fac[MAXN];
inline bool check(){
	for(int i=1;i<=n;i++) if(s[i]=='0') return false;
	return true;
}
signed main(){
	Freopen();
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m>>s+1;
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	int ans=0;
	do{
		int cnt=0,sum=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[p[i]] || s[i]=='0') cnt++;
			else sum++;
		}
		if(sum>=m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<'\n';
	return 0;
}

