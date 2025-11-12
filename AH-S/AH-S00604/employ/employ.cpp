#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
long long s=1;
int u;
long long p=0;
int n,m;
int f=1;
int main()
{	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==n)
	{
		cout<<0;return 0;
	}
	string b;
	cin>>b;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==0)
		{
			p++;
		}
	}
	sort(a+1,a+1+n);
	int flag=0;
/*	for(int i=1;i<=n;i++)
	{
		if(a[i]==0)
		{
			u++;
			flag=i;
		}
	}
	*/
	//if(m==1)
	//{
		for(int i=1;i<=n;i++)
		if(a[i]!=0&&a[i]>=i)
		{
			flag=i;
			break;
		}
		int k=1;
		/*for(int i=flag;i<=n;i++)
		{
			s=s*k%998244353;
			k++;
		}
		for(int i=1;i<=p;i++)
		{
			s*=i;
		*/
		if(!flag){cout<<0;return 0;}
	//}
	for(int i=0;i<b.size();i++)
	{
		if(b[i]=='0')
		{
			f=0;
		}
	}
	if(n-p<m)
	{
		cout<<0;return 0;
	}
	if(f)
	{
		for(int i=n;i>=1;i--)
		{
			s=s*i%998244353;
		}
		cout<<s;
		return 0;
	}
	for(int i=n;i>=1;i--)
		{
			s=s*i%998244353;
		}
		cout<<s;
		
}
