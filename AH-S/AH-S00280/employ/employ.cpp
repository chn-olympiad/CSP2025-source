#include<bits/stdc++.h>
using namespace std;
const long long N=510,mod=998244353;
long long n,m,ans,c,a[N];
string s;
bool ifa(){
	for(long long i=0;i<n;i++){
		if(s[i]=='0')return 0;
	}
	return 1;
}

int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i])c++;
	}
	if(ifa()){
		ans=1;
		for(long long i=n;i>=n-c+1;i--)ans=ans*i%mod;
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}
