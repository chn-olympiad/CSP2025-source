#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long b=a.length();
	int p[b];
	int c=0;
	for(int i=0;i<b;i++)
	{
		if(a[i]<='9'&&a[i]>='0')
		{
			p[c++]=a[i]-'0';
		} 
	} 
	sort(p,p+c);
	for(int i=c-1;i>=0;i--)
	{
		cout<<p[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
