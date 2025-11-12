#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
int sd(string a)
{
	for(int i=0;i<a.length();i++)
		if(a[i]==0)
			return i;
}
long long pow(int a)
{
	long long res=1;
	for(int i=2;i<=a;i++)
	{
		res=res*i%998244353;
	}
	return res;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(sd(s)!=m)
		cout<<0;
	else
		cout<<pow(n);
	return 0;
}
