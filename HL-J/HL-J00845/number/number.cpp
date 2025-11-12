#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int a[n];
	int laoda=0,b=0,ling=0,da=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='1')
		{
			a[i]=1;
			b++;
		}
		if(s[i]=='2')
		{
			a[i]=2;
			b++;
		}
		if(s[i]=='3')
		{
			a[i]=3;
			b++;
		}
		if(s[i]=='4')
		{
			a[i]=4;
			b++;
		}
		if(s[i]=='5')
		{
			a[i]=5;
			b++;
		}
		if(s[i]=='6')
		{
			a[i]=6;
			b++;
		}
		if(s[i]=='7')
		{
			a[i]=7;
			b++;
		}
		if(s[i]=='8')
		{
			a[i]=8;
			b++;
		}
		if(s[i]=='9')
		{
			a[i]=9;
			b++;
		}
		if(s[i]=='0')
			{
				b++;
				ling++;
			}
	}
			int c=b-ling;
			while(c--){
				laoda=0;
	for(int i=0;i<n;i++)
	{
    	if(a[i]>laoda)
    	{
    		laoda=a[i];
    		da=i;
		}
	}
	cout<<laoda;
	a[da]=0;
}
for(int i=1;i<=ling;i++)
{
	cout<<0;
}
	return 0;
}
