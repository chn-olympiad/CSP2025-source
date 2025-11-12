#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=510,P=998244353;



ll t,n,m,ans=0,c[N],minc=99999999999,cnt1;
string s;
inline ll get(ll n){
	ll ans=1;
	for(int i=2;i<=n;i++){
		ans*=i;
		ans%=P;
	}
	return ans;
}
bool f[N];
inline void dfs(ll id,ll cnt1){
	if(id>n){
		if(cnt1>=m) ans++;
		return ;
	}
	if(cnt1>=m){
		ans+=get(n-id+1);
		ans%=P;
		return ;
	}
	if(cnt1+n-id+1<m) return ;
	for(int i=1;i<=n;i++){
		if(f[i]) continue;
		f[i]=1;
		if(s[id-1]=='0'||id-cnt1-1>=c[i]) dfs(id+1,cnt1);
		else dfs(id+1,cnt1+1);
		f[i]=0;
	}
}

int main(){
	ios::sync_with_stdio(false);
//	cout<<get(100)<<endl;
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++) {
		cin>>c[i];
		minc=min(minc,c[i]);
		if(s[i-1]=='1') cnt1++;
	}
	
	
	if(m==n){
		if(cnt1<n||minc==0) cout<<0;
		else cout<<get(n)%P;
		return 0;
	}
	dfs(1,0);
	cout<<ans%P;
	return 0;
} 
