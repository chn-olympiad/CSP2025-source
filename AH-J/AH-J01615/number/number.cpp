#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a[s.size()],d=s.size();
	int b=0,c=0,e;
	for(int i=0;i<d;i++)
	{
		if(s[i]=='0')
		{
			a[b]=0;
			b++;
		}
		else if(s[i]=='1')
		{
			a[b]=1;
			b++;
		}
		else if(s[i]=='2')
		{
			a[b]=2;
			b++;
		}
		else if(s[i]=='3')
		{
			a[b]=3;
			b++;
		}
		else if(s[i]=='4')
		{
			a[b]=4;
			b++;
		}
		else if(s[i]=='5')
		{
			a[b]=5;
			b++;
		}
		else if(s[i]=='6')
		{
			a[b]=6;
			b++;
		}
		else if(s[i]=='7')
		{
			a[b]=7;
			b++;
		}
		else if(s[i]=='8')
		{
			a[b]=8;
			b++;
		}
		else if(s[i]=='9')
		{
			a[b]=9;
			b++;
		}
	}
	for(int i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
		{
			if(a[b]>c)
			{
				c=a[b];
				e=b;
			}
		}
		cout<<c;
		a[e]=0;
	} 
}
