#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool isdigit(char c)
{
	if(c>='0' and c<='9') return 1;
	return 0;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin) ;
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	string s;
	cin>>s;
	int n=0;
	for(int i=0;i<s.size();++i)
	{
		if(isdigit(s[i]))
		{
			n++;
			a[n]=s[i]-48;	
		}
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	cout<<a[i];
}//CCF is great(too diffcult!!!)

