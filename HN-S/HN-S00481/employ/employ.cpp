#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m; 
ll a[505],js[505],jl;
ll ans,cnt;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==n){
		cout<<1;
	}else{
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				js[cnt]=i;
				cnt++;
			}
		}
		for(ll j=0;j<cnt;j++){
			for(int i=0;i<n;i++){
				if(a[i]>=js[j]){
					ll c=1;
					for(ll k=n-1;k>1;k--){
						c*=k;
						c%=998244353;
					}
					ans+=c;
					ans%=998244353;
				}
			}
		}
		cout<<ans;
	}
	return 0;
} 
