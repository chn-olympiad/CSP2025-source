#include<bits/stdc++.h>
#define LL long long
using namespace std;
const LL MOD = 998244353;

LL n,m,spiderman,cnt1,cnt0,ans;
string s;
LL c[514];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			cnt1++;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0){
			cnt0++;
		}
	}
//	cout<<s<<'\n'<<cnt1<<'\n'<<cnt0<<'\n';
	if(cnt1<m||n-cnt0<m){//wujie
		cout<<0;
		return 0;
	}
	if(cnt1==n){
		ans = 1;
		for(int i=2;i<=n;i++){
			ans = (ans*i)%MOD;
		}
		cout<<ans;
		return 0;
	}
	
	
	ans = 1;
	for(int i=2;i<=min(m,n-cnt0);i++){
		ans = (ans*i)%MOD;
	}
	cout<<ans;
//	sort(c+1,c+n+1);
//	for(int i=1;i<=n;i++){//mei ju mian shi zhe
//		if(spiderman>=c[i]){
//			continue;
//		}
//		
//	}
	return 0;
}
/*
10 5
1111111111
6 0 4 2 1 2 5 4 3 3

*/
