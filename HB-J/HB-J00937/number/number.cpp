#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1000004];
	bool n[1000004];
	cin>>s;
	int t=0,m=int(s.size());
	for(int i=0;i<=int(s.size());i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[t]=s[i]-48;
			n[t]=true;
			t++;
		}
	}
	while(m--)
	{
		for(int i=1;i<=int(s.size());i++)
		{
			if(a[i]>a[i-1])
			{
				int u;
				u=a[i];
				a[i]=a[i-1];
				a[i-1]=u;
			}
		}
	}
	for(int i=0;i<=t+10000;i++)
	{
		if(n[i]==true)
		{
			cout<<a[i];
		}
	}
	
}
