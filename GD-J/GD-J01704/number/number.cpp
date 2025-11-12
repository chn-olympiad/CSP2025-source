#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
int num;
bool cmp(long long a,long long b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i])) 
		{
			a[num]=int(s[i]-48);
			num++;
		}
	}
	sort(a,a+num,cmp);
	for(int i=0;i<num;i++)
	{
		cout<<a[i];
	}
	return 0;
}
