#include<bits/stdc++.h>
using namespace std;
string a,x[15];
int main()
{
  freopen("number.in","r",stdin);
  freopen("number.out","w",stdout);
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			x[a[i]-'0']+=a[i];
		}
	}
	for(int i=9;i>=0;i--)
	{
		if(x[i].size()>0)
		cout<<x[i];
	}
	return 0;
}
