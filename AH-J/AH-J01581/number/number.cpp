#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	int l=s.size();
	int a[l],x=0;
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
		a[x]=s[i]-'0';
		x++;
		}
	}
	for(int i=0;i<x;i++)
	{
	for(int j=i;j<x;j++)
	{	if(a[j]>=a[i])
		swap(a[i],a[j]);
	}
	}
	for(int i=0;i<x;i++)
	{
		cout<<a[i];
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
