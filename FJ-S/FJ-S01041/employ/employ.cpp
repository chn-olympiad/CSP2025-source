#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll n,m,c[505],ans;
string a;
bool flag=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>a;
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
	for(ll i=0;i<n;i++){
		if(a[i]=='0'){
			flag=0;
			break;
		}
	}
	if(flag){
		ans=1;
		for(ll i=1;i<=n;i++) ans=ans*i%mod;
		printf("%lld",ans);
	}
	return 0;
}
