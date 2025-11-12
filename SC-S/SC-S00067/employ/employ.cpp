#include<bits/stdc++.h>
using namespace std;
int n,m;
char s[500+5];
int c[500+5];
int gs1;
int main()
{
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='1')
		{
			gs1++;
		}
		else if(s[i]=='0' and m==n)
		{
			cout<<"0";
			return 0;
		}
	}
	cout<<gs1<<endl;
	if(gs1==n)
	{
		long long q=1;
		for(long long i=1;i<=n;i++)
		{
			q=q*i%998244353;
			cout<<q<<endl;
		}
		q=q%998244353;
		cout<<q;
	}
	return 0;
}