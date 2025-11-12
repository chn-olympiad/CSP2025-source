#include<bits/stdc++.h>
namespace cxk{
	using namespace std;
	#define ll long long
	#define md 998244353
	ll n,m,ans,c[505],ix[505];
	string s;
	int main(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(nullptr);
		cout.tie(nullptr);
		cin>>n>>m>>s;
		s=" "+s;
		ll g1=0,mn=0;
		for(auto it:s)if(it=='1')g1++;
		if(m>g1){
			cout<<0;
			return 0;
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
			ix[i]=i;
			mn=min(mn,c[i]);
		}
		if(m==n){
			if(g1!=n||mn==0)cout<<0;
			else{
				ll ans=1;
				for(int i=1;i<=n;i++)ans=ans*i%md;
				cout<<ans;
			}
			return 0;
		}
		do{
			ll kl=0;
			for(int i=1;i<=n;i++)if(kl>=c[ix[i]]||s[i]=='0')kl++;
			if(n-kl>=m)ans++;
		}while(next_permutation(ix+1,ix+1+n));
		cout<<ans;
		return 0;
	}
}
int main(){return cxk::main();}
