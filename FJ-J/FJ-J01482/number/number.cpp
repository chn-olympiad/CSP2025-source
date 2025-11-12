#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int b[n+5]={-1};
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			b[i]=s[i]-'0';
		}
		else
			b[i]=-1;
	}
	sort(b,b+n,cmp);
	for(int i=0;i<n;i++)
	{
		if(b[i]!=-1)
			cout<<b[i];
	}
	return 0;
}
