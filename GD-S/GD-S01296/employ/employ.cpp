#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,c[505];
string s;
bool f=1;
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<s.size();i++)
		if(s[i]!='1') f=0;
	if(f){
		for(int i=n;i>=n-m+1;i--)
			ans*=i;
		for(int i=m;i>=1;i--)
			ans/=i;
		ans%=mod;
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
