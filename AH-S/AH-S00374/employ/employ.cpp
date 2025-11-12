#include<bits/stdc++.h>
using namespace std;
int n,m,a[510],t;
int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	long long ans=1,k=0;
	int p=s.size();
	for(int i=0;i<p;i++)
		if(s[i]=='0')
			t=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
			k++;
	}
	for(long long i=1;i<=n;i++)
	{
		ans=(ans*i)%998244353;
	}
	cout<<ans;
    return 0;
}
