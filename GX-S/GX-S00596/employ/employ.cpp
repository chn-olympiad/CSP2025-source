#include<bits/stdc++.h>
using namespace std;
const int N=505,mod=998244353;
int b[N];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string a;
	cin>>a;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int n1=a.size();
	int f=0,s=0;
	for(int i=0;i<n1;i++)
		if(a[i]=='0')
		{
			f=1;
			s++;
		}
	if(f==0)
	{
		cout<<0;
		return 0;
	}
	if(m==1)
	{
		int s=1;
		for(int i=1;i<=n;i++)
			s=(s*i)%mod;
		cout<<s<<endl;
	}
	else if(m==n)
		cout<<0;
	return 0;
}
