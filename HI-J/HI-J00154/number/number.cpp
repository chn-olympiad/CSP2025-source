#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s[1000000]={};
	
	int cnt=0;
	for(int i=1;i<=s[1000000].size();i++)
	{
		cin>>s[i];
	}
	for(int i=0;i<=s[1000000].size();i++)
	{
		char(s[i]);
		if(s[i]<'a')
	 {
			cnt++;
			a[cnt]=s[i];
	 }
	}
	for(int i=0;i<=cnt-1;i++)
	{
		for(int j=0;j<=cnt-1;j++)
		{
		if(a[i]<=a[i+1])
		{
			a[i]=a[i+1];
		}
		cout<<a[i]<<" ";
	}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
