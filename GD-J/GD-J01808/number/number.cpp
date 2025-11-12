#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int t[15]={};
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0'&&a[i]<='9')t[a[i]-'0']++;
	} 
	for(int i=9;i>=0;i--)
	{
		while(t[i])
		{
			t[i]--;
			cout<<i;
		}
	}
	return 0;
 } 
