#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
string s,n;
long long m,a[1000005];
int main()
{
	cin >>s;
	m=s.length();
	for(int i=0;i<m;i++)
	{
		if(s[i]<=58)
		{
			n+=s[i];
			a[i]=s[i]-48;
		}
	}
	sort(a+1,a+m+1,cmp);
	m=n.length();
	for(int i=0;i<m;i++)
	{
		cout <<a[i];
	}
	return 0;
}

