#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace{
	int p[15],a[15];string s;
	void MAIN(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		int n,m,ans=0;
		cin>>n>>m;
		iota(p+1,p+n+1,1);
		cin>>s,s=" "+s;
		bool SpecialA=1;
		for(int i=1;i<=n;i++) SpecialA&=(s[i]==49);
		if(SpecialA){
			int ans=1;
			for(int i=1;i<=n;i++) ans=ans*i%998244353;
			cout<<ans,exit(0);
		}
		for(int i=1;i<=n;i++) cin>>a[i];
		do{
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(s[i]==48||cnt>=a[p[i]]) cnt++;
			ans+=(n-cnt>=m);
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
}
signed main(){MAIN();}
//100+[56,100]+[25,60]+28=[209,288]，基本能 1= 了吧。/gg 估计一堆 300pts 的. 

