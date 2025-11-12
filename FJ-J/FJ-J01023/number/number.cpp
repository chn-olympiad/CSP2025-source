#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a[11],b[100000],ans=0,t=0,c=1,m;
	string s;
	cin >> s;
	m=s.size();
	for(int i=0;i<=9;i++)
	{
		a[i]=0;
	}
	for(int i=0;i<m;i++)
	{
		if(s[i]<='9'&&s[i]>='0')	
		{	
			int n=s[i]-'0';
			b[i]=n;
			a[n]++;
		}
	}
	for(int i=0;i<=9;i++)
	{
		t+=a[i];
		
	}
	sort(b,b+m,cmp);
	for(int i=0;i<t;i++)
	{
		cout << b[i];
	}
	return 0;
}