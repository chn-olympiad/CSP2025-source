#include<bits/stdc++.h>
using namespace std;
string s;
int l,ii=1,a[1000010];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.size()-1;
	for(int i=0;i<=l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[ii]=s[i]-'0';
			ii++;
		}
	}
	ii--;
	sort(a+1,a+ii+1,cmp);
	for(int i=1;i<=ii;i++)
	{
		cout<<a[i];
	}
	return 0;
}
