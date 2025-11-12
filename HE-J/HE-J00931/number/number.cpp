#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int b[1000],c=0;
	string a;
	cin>>a;
	for(int i=1;i<=a.length();i++)
	{
			if(a[i]=='1')
			{
				b[i]=1;
			}
			if(a[i]=='2')
			{
				b[i]=2;
			}
			if(a[i]=='3')
			{
				b[i]=3;
			}
			if(a[i]=='4')
			{
				b[i]=4;
			}
			if(a[i]=='5')
			{
				b[i]=5;
			}
			if(a[i]=='6')
			{
				b[i]=6;
			}
			if(a[i]=='7')
			{
				b[i]=7;
			}
			if(a[i]=='8')
			{
				b[i]=8;
			}
			if(a[i]=='9')
			{
				b[i]=9;
			}
			if(b[i]<b[i+1])
			{
				c=b[i];
				b[i]=b[i+1];
				b[i+1]=c;
			}
	} 
	for(int i=1;i<=a.length();i++)
	{
		cout<<b[i];
	}
	return 0;
}  
