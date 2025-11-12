#include<bits/stdc++.h>
using namespace std;
char c[1000050];
int main()
{
/*	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);*/
	string s;
	int a=0;
	char b;
	cin>>s;
	c[0]='1';
	c[1]='2';
    for(int i=0;i<s.size();i++)
	{
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0')
		{
		    c[a]=s[i];
			a++;
			b=s[i];
		}
	}
	if(a==1) 
	{
	    cout<<b;
	    return 0;
	}

	for(int i=0;i<a;i++)
	{
		for(int j=i+1;j<a;j++)
		{
			if(c[i]<c[j])
			{
				swap(c[i],c[j]);
			}
		}
	}
	for(int i=0;i<a;i++) cout<<c[i];
	return 0;
 } 
