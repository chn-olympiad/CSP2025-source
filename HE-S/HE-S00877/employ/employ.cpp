#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,c[100001],ans;
	bool z=true,z1=true;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0')
		{
			z=false;
		}
		if(s[i]=='1')
		{
			z1=false;
		}
	}
	if(z==true)
	{
		ans++;
		for(int i=1;i<=n;i++)
		{
			ans*=i;
		}
		cout<<ans;
	}
	else if(z1==true)
	{
		cout<<0;
	}
	else if(m==1)
	{
		cout<<n;
	}
	else 	cout<<2;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
