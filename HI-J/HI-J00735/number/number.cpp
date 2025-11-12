#include<bits/stdc++.h>
using namespace std;
int s[1000005];
bool pai(int n,int m)
{
	return n>m;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long s_=0;
	for(long long i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			s[s_]=a[i]-'0';
			s_++;
		}
	}
	sort(s+0,s+s_,pai);
	for(int i=0;i<s_;i++)
	{
		cout<<s[i];
	}
	return 0;
}
