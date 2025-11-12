#include<iostream>
#include<cstdio>
#define p 998244353
using namespace std;
int f(int n)
{
	int ret=1;
	for(int i=2;i<=n;i++) ret=ret*i%p;
	return ret;
}
int main()
{
	//freopen("employ.in","r",stdin);
	//freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	char c;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c;
		if(c=='1') cnt++;
		if(c=='0')
		{
			if(cnt<m)
			{
				cout<<0;
				return 0;
			}
		}
	}
	cout<<f(n);
	return 0;
}