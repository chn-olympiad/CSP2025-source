#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),t=0;
	int a[n];
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			a[t]=s[i]-'0';
			t++;
		}
	}
	sort(a,a+t,cmp);
	for(int i=0;i<t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
