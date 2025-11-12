#include <bits/stdc++.h>
using namespace std;
int b[1000005];
int c[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,a;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&
		s[i]<='9')
		a+=s[i];
	}
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='0')b[i+1]=0;
		if(a[i]=='1')b[i+1]=1;
		if(a[i]=='2')b[i+1]=2;
		if(a[i]=='3')b[i+1]=3;
		if(a[i]=='4')b[i+1]=4;
		if(a[i]=='5')b[i+1]=5;
		if(a[i]=='6')b[i+1]=6;
		if(a[i]=='7')b[i+1]=7;
		if(a[i]=='8')b[i+1]=8;
		if(a[i]=='9')b[i+1]=9;
	}
	int l=a.size();
	sort(b+1,b+l+1);
	for(int i=1;i<=a.size()-1;i++)
	{
		cout <<b[i];
	}

//	for(int i=l;i>=3;i--)
//	{
//		cout<<b[i];
//	}
	cout<<b[0];
	return 0;
 } 
