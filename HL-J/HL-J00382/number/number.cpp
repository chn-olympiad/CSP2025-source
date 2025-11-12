#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	int a[1005],cpp=0,t;
	cin>>x;
	for(int i=0;i<=x.size();i++)
	{
		if(x[i]>='0' && x[i]<='9')
		{
			t=int(x[i])-48;
			a[cpp]=t;
			cpp++;
		}
	}
	int n=cpp;
	sort(a,a+n+1);
	for(int i=cpp;i>0;i--)
	{
		cout<<a[i];
	}
	return 0;
}