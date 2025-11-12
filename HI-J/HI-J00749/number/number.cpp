#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,w;
	cin>>s;
	int maxi=0,cnt=0,a[10000001];
	for(int i=0;i<s.size();i++)
	{
		if(s[i]%2==0||s[i]%2!=0)
		{
			w+=s[i];
		}
		a[i]=w[i]/'0';
	}
	int n=w.size();
	for(int j=0;j<=n;j++)
	{
		if(a[j]<a[j+1])
		{
			swap(a[j],a[j+1]);
		}
	}
	cout<<a[n];
	fcolse(stdin);
	fcolse(stdout);
	return 0;
}
