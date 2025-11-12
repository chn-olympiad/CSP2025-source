#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=510;
const ll M=998244353;
ll n,m,c[N],cnt,ans,a[N],vis[N];
string s;
void dfs(ll k,ll cnt){
	if(k>n){
//		for(ll i=1;i<=n;i++) cout<<a[i]<<" ";
//		cout<<endl;
//		cout<<cnt<<endl;
		if(cnt>=m) ans++;
		return;
	}
	for(ll i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			a[k]=i;
			if(s[k-1]=='0' || k-1-cnt>=c[i]) dfs(k+1,cnt);
			else dfs(k+1,cnt+1); 
			vis[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(ll i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
//	cout<<cnt<<endl;
	if(m>n-cnt){
		cout<<0;
		return 0;
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
