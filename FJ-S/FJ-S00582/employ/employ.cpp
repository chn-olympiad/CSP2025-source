#include<bits/stdc++.h>
using namespace std;
#define N 514
#define mod 998244353
int n,m;
long long ans=1;
int c[N];
string str;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	bool f=1;	
	for(int i=0;i<str.size();i++)
		if(str[i]=='0') f=0;
	if(f){
		for(int i=1;i<=n;i++)
			ans=(1ll*i*ans)%mod;
		cout<<ans;	
	}else	
		cout<<0;		
	return 0;
}
