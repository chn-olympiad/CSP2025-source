#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.length(),j=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]==1||s[i]==2||s[i]==3||s[i]==4||s[i]==5||s[i]==6||s[i]==7||s[i]==8||s[i]==9||s[i]==0)
		{
			a[j]=s[i];
			j++;
		}
	}
	for(int i=1;i<=j;i++)
	{
		cout<<a[i];
	}
	return 0;
}
