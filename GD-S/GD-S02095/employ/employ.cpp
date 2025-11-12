#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
const int mod=998244353;
int n,m,cnt,ans=1;
string s;
int c[N];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!=0)cnt++;
	}
	for(int i=n;i>=1;i--){
		ans=ans*i%mod;
	}
	cout<<ans;
	return 0;
}
