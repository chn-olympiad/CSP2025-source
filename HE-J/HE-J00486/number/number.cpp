#include<bits/stdc++.h>
using namespace std;

string s;
int a[1000009];
long long n;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		if(s[i]>=48&&s[i]<=57)
			a[++n]=s[i]-48;
	}
	sort(a+1,a+n+1,cmp);
	for(long long i=1;i<=n;i++)
		cout<<a[i];
	return 0;
}
