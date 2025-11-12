#include<bits/stdc++.h>
using namespace std;

map<string,int>mp[10000];

int shibie1(int n,string s)
{
	long long x=0;
	bool di=true;
	for(int i=0; di==true&&i<n; i++)
	{
		int q=s[i]-'0';
		if(q<=9&&q>=0)
		{
			x=(x+q)*10;
		}
		else
		{
			di=false;
		}
	}
	return x/10;
}
int shibief(int n,int ff[9],string s)
{
	int q=s[i]-'0';
	if(isalpha(q))
	{
		return 1;
	}
	int i;
	for(i=0; i<n; i++)
	{
		q=s[i]-'0';
		if(q>9||q<0)
		{
			break;
		}
	}
	q=s[i];
	for(int i=0; i<8; i++)
	{
		if(q==ff[i])
		{
			return i+1;
		}
	}
	return -1;
}
int shibie2(int n,string s)
{
	int i;
	for(i=0; i<n; i++)
	{
		int q=s[i]-'0';
		if(q>9||q<0)
		{
			i++;
			break;
		}
	}
	long long x=0;
	for(i=i; i<n; i++)
	{
		int q=s[i]-'0';
		if(q<=9&&q>=0)
		{
			x=(x+q)*10;
		}
	}
	return x/10;
}
long long cnt(long long a,long long b,long long f)
{
	if(f==1)
	{
		return a+b;
	}
	if(f==2)
	{
		return a-b;
	}
	if(f==3)
	{
		return a*b;
	}
	if(f==4)
	{
		return a/b;
	}
	if(f==5)
	{
		b=1;
		for(long long i=1; i<=a; i++)
		{
			b*=i;
		}
		return b;
	}
	if(f==6)
	{
		return pow(a,b);
	}
	if(f==7)
	{
		return sqrt(a);
	}
	if(f==8)
	{
		return a%b;
	}
}

int main()
{
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	cout<<">>";
	while(true)
	{
		int n,f;
		long long a,b;
		int ff[9]= {43,45,42,47,33,94,39,37,128};
		string s;
		cin>>s;
		n=s.size();
		if(s[0]=='^'&&s[1]=='z'||s[0]=='^'&&s[1]=='Z')
		{
			return 0;
		}
		a=shibie1(n,s);
		f=shibief(n,ff,s);
		b=shibie2(n,s);
		cout<<cnt(a,b,f)<<endl<<">>";
	}
}
