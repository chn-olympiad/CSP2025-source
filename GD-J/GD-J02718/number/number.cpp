#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],d,p;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	d=s.size();
	for(int i=0;i<d;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		  a[++p]=s[i]-48;
	}
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=p;i++)
	  cout<<a[i];
	return 0;
}
