#include<bits/stdc++.h>
using namespace std;
int n,m,c[510],mod=998244353,ans,sl1,sl0;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='1')
			sl1++;
	int ans=1;
	for(int i=2;i<=sl1;i++)
		ans*=i;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+1+n);
	cout<<ans%mod;
	return 0;
}
//10 5
//101111011
//6 0 4 2 1 2 5 4 3 3
