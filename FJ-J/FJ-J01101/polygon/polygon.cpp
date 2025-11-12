#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const ll mod=998244353;

int n;
int a[5005];
int ans=0;
bool vst[5005];

void dfs(int k){
	if(k>n){
		int sm=0,mx=0;
		for(int i=1;i<=n;i++){
			if(vst[i]){
				sm+=a[i]; mx=max(mx,a[i]);
			}
		}
		if(sm>2*mx) ans++;
		ans%=mod;
		return;
	} 
	vst[k]=0; dfs(k+1);
	vst[k]=1; dfs(k+1);
}

ll qpow(ll a,ll b){ // I know it's not quick but it's safe
	ll res=1;
	for(int i=1;i<=b;i++) res=res*(a%mod)%mod;
	return res%mod;
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("polygon.in","r",stdin); freopen("polygon.out","w",stdout);
	cin>>n;
	int spj=-114514;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		spj=max(spj,a[i]);
	}
	if(spj==1){
		cout<<(qpow(2,n)-n-n*(n-1)/2-1+mod)%mod<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans%mod<<endl;
	return 0;
}

//==============================T4==============================//
// xiang jin CSP-J/S2025 mi huo xing wei da shang
// freopen("number.in","r",stdin)
// freopen("number.in","w",stdin)
// freopen("number.out","r",stdout)
// freopen("number4.in","r",stdin)
// int mian
// itn nit
//==============================================================//
// my luogu uid is 693282 please guan zhu me
// I want to AFO because of whk and PE
// but I want to get a good score in CSP-J/S2025
// maybe I should AFO if I get <1= on CSP-J or get <2= on CSP-S
//==============================================================//
// gu fen: 100+100+30+64=294
//==============================================================//
