#include<bits/stdc++.h>
using namespace std;
long long const F=998244353;
int n,m;
string s;
int const D=600;
int p[D];
bool off=false;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='1')off=true;
	}
	if(off==false){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans=(ans*i)%F;
		}
		cout<<ans%F;
		return 0;
	}
	
	return 0;
}
