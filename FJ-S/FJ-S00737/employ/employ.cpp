#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int N=505;
int n,m,cnt,ans=1,c[N];
string s;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(!c[i])cnt++;
	}
	if(cnt<=m){
		for(int i=1;i<=n;i++)ans=ans*i%mod;
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
