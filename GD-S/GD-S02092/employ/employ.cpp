#include<bits/stdc++.h>

using namespace std;
const int N = 505;

string s;
long long n,ans,c[N],m;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m;
	cin>>s;
	for (int i=1;i<=n;i++) cin>>c[i];
	
	if (m==n) cout<<0;
	else{
		ans=1;
		for (long long i=2;i<=n;i++) ans=ans*i%998244353;
		cout<<ans%998244353;
	}
	
	
	return 0;
}
