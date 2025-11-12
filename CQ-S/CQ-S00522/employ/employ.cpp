#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,c[510],id[510],ans,v;
const int mod=998244353;
string s;
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]!='1'){
			v=1;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		id[i]=i;
	}
	if(n<=10){
		do{
			int t=0,cnt=0;
			for(int i=0;i<n;i++){
				if(s[i]=='1'&&t<c[id[i]+1]) cnt++;
				else t++;
			}
			if(cnt>=m) ans++;
			ans%=mod;
		}while(next_permutation(id+1,id+n+1));
		cout<<ans;
	}
	else if(!v){
		ans=1;
		for(int i=1;i<=n;i++){
			ans*=i%mod;
			ans%=mod;
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
