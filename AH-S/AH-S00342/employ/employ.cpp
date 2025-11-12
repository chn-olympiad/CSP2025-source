#include <bits/stdc++.h>
#define int long long
using namespace std;
int Mod=998244353;
string s;
int a[100050];
signed main()
{
		freopen("employ.in","r",stdin);
	freopen("employ","w",stdout);
	int ans=1;
	bool uuu=1;int cnt=0;
	int n,m;cin>>n>>m;
		cin>>s;
		for(int i=0;i<n;i++){
		if(s[i]=='0'){
			uuu=0;
		}
		cin>>a[i];
		if(a[i]!=0) cnt++;
		}
		if(uuu){
			if(cnt>m){
				for(int i=cnt;i>=cnt-m+1;i--){
					ans*=i;
					ans%=Mod;
					cout<<ans<<'\n';
					}
			}
			int xxx=1;
			for(int i=1;i<=n-m;i++){
				xxx*=i;
				xxx%=Mod;
				}
				ans*=xxx;ans%=Mod;
		}
	else{
		
	}
	cout<<ans;
}
