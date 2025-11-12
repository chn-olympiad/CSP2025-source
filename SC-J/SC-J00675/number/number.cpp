#include<bits/stdc++.h>
using namespace std;
string s;
int a[10000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int k=s.size();
	int n=0;
	for(int i=0;i<=k;i++)
	{
		if(int(s[i])>=int('0')&&int(s[i])<=int('9'))
		{
			a[i]=int(s[i])-int('0');
			n+=1;
		}
	}
	sort(a,a+k);
	for(int i=k-1;i>=k-n;i--)
	{
			cout<<a[i];
	}
}