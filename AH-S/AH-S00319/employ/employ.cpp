#include <bits/stdc++.h>
using namespace std;
#define maxn 600
#define ll long long
#define mod %=998244353
int a[maxn];
int b[maxn];

int j(ll x,ll y){
	ll ans=1;
	for(ll i=1;i<=y;i++){
		ans*=x;
		x-=1;
		ans mod;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	string str;
	cin>>str;
	
	for(int i=1;i<=n;i++) cin>>a[i];

	//special 15
	if(m==n){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		ll ans=0;
		ll cnt=0;
		for(int i=1;i<=n;i++){
			cnt++;
			if(b[i]!=0){
				ans+=j(cnt,b[i]);
				cnt-=b[i];
				
				ans mod;
			}
			//cout<<ans<<" "<<cnt<<" \n";
		}
		ans mod;
		cout<<ans;
	}

	return 0;
}
