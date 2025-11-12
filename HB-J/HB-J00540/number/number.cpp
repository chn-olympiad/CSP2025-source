#include<bits/stdc++.h>
using namespace std;
int a,b,i;
string s,c;
int t[10000005];


int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
	cin>>s;
	a=s.size();
	for(i=0;i<a;i++)
	{
		if(s[i]=='0'||s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9')
		{
		c[b]=s[i];
		b++;
		}
		
	}
	for(i=0;i<b;i++)
	{
		t[i]=c[i]+'0';
	}
	for(i=0;i<b;i++)
	{
		int ans;
		ans=t[i];
			for(int j=i;j<b;j++)
		{
			if(t[j]>ans)
			{
				ans=t[j];
				t[j]=t[i];
				
			}	
			t[i]=ans;
		}
		
	}
	i=0;
	for(i=0;i<b;i++)
	{
		for(int j=0;j<b;j++)
	{
		if(t[i]==c[j]+'0')
		{
			cout<<c[j];
			break;
		}
			
	}
	}
	return 0;
}

