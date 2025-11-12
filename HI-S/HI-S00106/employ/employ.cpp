#include<bits/stdc++.h>
using namespace std;
long long n,m,b[600],q,qq,s=1;
char a[600];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		q=1;
	}
	for(int i=0;i<n;i++)
	{
		cin>>b[i];
	}
	if(q==1)
	cout<<0;
	else if(q==0)
	{
		for(int i=1;i<=n;i++)
		s*=i;
		cout<<s%998244353;
	}
	return 0;
}//1*2*3*4
