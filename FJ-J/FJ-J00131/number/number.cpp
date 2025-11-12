#include<bits/stdc++.h>
using namespace std;
priority_queue <int> q;
int a[1000000];
long long xf(long long x)
{
	long long num=1;
	for(int i=1;i<x;i++)
	{
		num*=10;
	} 
	return num;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int l=0;
	cin>>s;
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-'0'<=9)
		{
			a[i]=s[i]-'0';
			l++;
		}
	}
	for(int i=0;i<s.size();i++)
	{
		q.push(a[i]);
	}
	long long m=0;
	for(int i=l;i>0;i--)
	{
		long long c=xf(i);
		m=m+(q.top()*c);
		q.pop();
	}
	cout<<m;
	return 0; 
}
