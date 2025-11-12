#include<bits/stdc++.h>
using namespace std;
int u[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,w="";
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			w+=a[i];
		}
	}
	int n=w.length();
	for(int i=0;i<n;i++)
	{
		u[i]=int(w[i]-'0');
	}
	sort(u,u+n);
	for(int i=n-1;i>=0;i--)
	{
		cout<<u[i];
	}
	return 0;
}
