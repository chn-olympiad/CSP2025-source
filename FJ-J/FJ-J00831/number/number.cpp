#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;
string a;
int b[105];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size();i++)
	{
		 if(a[i]>='0'&&a[i]<='9')
		 {
		 	b[int(a[i])]+=1;
		 }
	}
	for(int i=60;i>=48;i--)
	{
		for(int j=1;j<=b[i];j+=0) 
		{
		if(b[i]>0)			
		{
			cout<<i-48;
			b[i]--;
		}
	}
}
	return 0;
}
