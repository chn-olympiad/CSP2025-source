#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[100000],p[100000],vis[100000],ans;
string s;
void dfs(ll t){
	if(t>n){
	//	for(ll i=1;i<=n;i++) cout<<p[i]<<" ";
	//	cout<<"\n";
		ll lp=0;
		for(ll i=0;i<s.size();i++){
			if(i-lp>=p[i+1]) continue;
			if(s[i]=='1') lp++;
		//	cout<<s[i];
		}
		//cout<<lp<<"\n";
		if(lp>=m) ans++;
		ans%=998244353;
	}
	else{
		for(ll i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				p[t]=a[i];
				dfs(t+1);
				vis[i]=0;
			}
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	ll flag=1;
	for(ll i=0;i<s.size();i++) if(s[i]!='1'){
		flag=0;
		break;
	}
	ll k=0;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) k++;
	}
	if(flag){
		ll sum=1;
		//cout<<n-k<<" ";
		for(ll i=1;i<=n-k;i++){
			sum*=i;
			sum%=998244353;
		}
		cout<<sum;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}

