#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,x;
	int num=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			x+=s[i];
			num++;	
			
		}
	}
	for(int i=0;i<num;i++)
	{
		char y;
		for(int j=i+1;j<=num;j++)
		{
			if(x[i]<x[j])
			{
				y=x[i];
				x[i]=x[j];
				x[j]=y;
			}
		}
	}
	cout<<x;
	return 0;
 } 
