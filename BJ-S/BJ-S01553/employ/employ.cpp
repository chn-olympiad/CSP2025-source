#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int Mod = 998244353;
int a[N],cnt,n,m,c[N],dp[N][N][N];
string s;
inline void solve1(){
	for(int i=1;i<=n;i++) a[i]=i;
	int ans=0;
	do{
		int cnt=0,num=0;
		for(int i=1;i<=n;i++){
			if(cnt<c[a[i]] && s[i-1]=='1') num++;
			else cnt++;
		}
		if(num>=m) ans++; ans%=Mod;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans<<'\n';
}
signed main(){

	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10) solve1();
	return 0;
}