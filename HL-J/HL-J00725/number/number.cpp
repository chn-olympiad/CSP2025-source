#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size(),cnt=0;
	int v[n];
	if(n==1)
	{
		cout<<s;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		v[i]=-1;
		if(s[i]=='1' or s[i]=='2' or s[i]=='3' or s[i]=='4' or s[i]=='5' or s[i]=='6' or s[i]=='7' or s[i]=='8' or s[i]=='9' or s[i]=='0')
		{
			v[i]=int(s[i])-48;
			cnt++;
		}
	}
	sort(v,v+n);
	for(int i=n-1;i>=1;i--)
	{
		if(v[i]!=-1)	cout<<v[i];
	}
	
	return 0;
}
