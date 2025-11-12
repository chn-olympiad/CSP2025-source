#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e2+10,mod=998244353;
ll n,m,c[maxn],a[maxn];
char s[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>(s+1);
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		a[i]=i;
	}
	ll ans=0;
	do{
		ll h=0;
		for(int i=1;i<=n;i++){
			if(s[i]=='0'){
				h++;
				continue;
			}
			if(h>=c[a[i]]){
				h++;
				continue;
			}
		}
		ans=(ans+((n-h)>=m))%mod;
	}while(next_permutation(a+1,a+n+1));
	cout<<ans<<"\n";
	return 0;
}
