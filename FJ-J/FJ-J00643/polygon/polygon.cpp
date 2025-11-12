#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 214514;
const int mod = 998244353;
int _,n,m,k,t,a[N],b[N],ans,cnt,tot;
string s;
bool vis[N],f;
map<int, int> mp;
void dfs(int x,int op,int mx,int sl){
	if(x==n+1){
		if(sl>=3&&op>2*mx){
			ans++;
		}
		return ;
	}
	dfs(x+1,op+a[x],max(mx,a[x]),sl+1);
	dfs(x+1,op,mx,sl);
}
int ksm(int po,int b){
	int a=po;
	int op=1;
	int bb=b;
	while(bb){
		if(bb&1){
			op*=a%mod;
			op%=mod;
		}
		a=(a*a)%mod;
		bb/=2;
	}
	return op%mod;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	b[1]=1;
	for(int i=2;i<=5000;i++){
		b[i]=b[i-1]*i;
		b[i]%=mod;
	}
	if(a[n]==1){
		for(int i=1;i<=n-3;i++){
			ans+=(b[n]*ksm(b[i],mod-2))%mod;
			ans%=mod;
		}
		ans+=b[n];
		ans%=mod;
		cout<<ans;
		return;
	}
	else{
		ans=0;
		dfs(1,0,0,0);
		ans%=mod;
		cout<<ans;
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	_=1;
	while(_--){
		solve();
	}
}
