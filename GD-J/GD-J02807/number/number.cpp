#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int num[15]={0};
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]<='9'&&a[i]>='0') num[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=1;j<=num[i];j++) cout<<i;
	}
	return 0;
 } 
