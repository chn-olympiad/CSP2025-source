#include<bits/stdc++.h>
using namespace std;
string s;	
int a[10000]={-1};
void p();	
int main()
{
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[i]=s[i]-'0';
		}
		else{
			a[i]=-1;
		}
	}
	for(int i=0;i<=s.size();i++)
	{
		p();
	}
	return 0;
}
void p()
{
	int j=-1;
	for(int i=0;i<=s.size();i++)
	{
		if(a[i]>j)
		j=a[i];
	}
	for(int i=0;i<=s.size();i++)
	{
		if(j==a[i])
		a[i]=-1;
	}
	if(j!=-1)
	cout<<j;
}
