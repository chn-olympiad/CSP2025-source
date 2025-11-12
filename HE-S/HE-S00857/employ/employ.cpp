#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int mod=998244353;
int n,m,ans;
string s;
int c[1000];
int A(int x,int y){
	int res=1;
	for(int i=y+1;i<=x;i++) res=res%mod*i%mod;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	int nn=0;
	for(int i=1;i<=nn;i++){
		cin>>c[i];
		if(c[i]==0) nn++;
	}
	if(s.find("0")==-1){
		if(n-nn<m) cout<<0;
		else{
			ans+=A(n,m);
			cout<<ans%mod;
		}
	}else cout<<0;
	return 0;
}
