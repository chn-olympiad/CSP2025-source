#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,a[505],s2=0,tmp=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0) s2++;
	}
	sort(a+1,a+n+1);
	for(int i=0;i<s.size();i++)
		if(s[i]!='1') tmp=0;
	if(n-s2<k)
	{
		cout<<0;
		return 0;
	}
	if(k==n)
	{
		if(tmp==0) cout<<0;
		if(s2!=0) cout<<0;
		long long sum=1;
		for(int i=1;i<=n;i++) sum*=i;
		cout<<sum;
		return 0;
	}
	cout<<0;
	return 0;
}
