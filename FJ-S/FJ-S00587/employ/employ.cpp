#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2145145;
const int mod = 998244353;
int _,n,m,k,t,a[N],b[N],ans,cnt,tot,op[N];
bool f,vis[N];
string s;
void solve(){
	ans=1;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		ans*=i;
		ans%=mod;
	} 
	cout<<ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_=1;
	while(_--){
		solve();
	}
	return 0; 
}
