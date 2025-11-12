#include<bits/stdc++.h>
using namespace std;
long long jc(int n)
{
	long long ans=1;
	for(int i=1;i<=n;i++)
	ans*=i;
	return ans;
}
long long n,m,c[600],p;
string s;
int main()
{
    freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	set<string> cut;
	cut.insert(s);
	for(set<string>::iterator it=cut.begin();it!=cut.end();it++)
	{
		string t=*it;
		int ans=0;

	}
	p=jc(n)/(jc(m)*jc(n-m));
	cout<<p%998244353<<endl;
	return 0;
}