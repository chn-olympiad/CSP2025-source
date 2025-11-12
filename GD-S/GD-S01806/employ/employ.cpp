#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s,u;
int a[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=n;i>=1;i--)
	{
		u="1"+u;
		if(s[i]=='0')
			for(int j=1;j<u.size();j++) u[j]++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=1;j<=n;j++){
			if(u[j]-'0'<=a[i])
			sum++;
		}
		ans*=(sum-i+1);
		ans%=998244353;
	}
	cout<<ans%998244353;
	return 0;
}

