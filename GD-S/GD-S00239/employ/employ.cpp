#include<cstdio>
#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0,mnx=0;
string s;
int c[505];
int main()
{
	freopen("stdin.employ","r",stdin);
	freopen("stdout.employ","w",stdout);
	cin>>n>>m;
	cin>>s;
	int ws1=0;
	for(int i=0;i<=505;i++)
	{
		if(s[i])
		{
			ws1++;
		}
		else
		{
			break;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]==0)
		{
			mnx++;
		}
	}
//	cout<<ws1;
	if(ws1==n)
	{
		long long jc=1;
		for(int i=1;i<=mnx;i++)
		{
			jc=(jc*i)%998224353;
		}
		for(int i=1;i<=n-mnx;i++)
		{
			jc=(jc*i)%998224353;
		}
		ans=jc;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
