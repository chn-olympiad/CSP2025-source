#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000001],k,n,j=0,m=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		k=s[i]-'0';
		if(k>=0&&k<=9)
		{
			++a[k];
	}
		if(k>m)
			m=k;
	}
	while(m>=0)
	{
		while(a[m]>0)
		{
			cout<<m;
		--a[m];
	}
	--m;
	}
	return 0;
}