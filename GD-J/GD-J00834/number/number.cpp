#include<bits/stdc++.h>
using namespace std;
long long a[1000009];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			
			a[j]=s[i]-'0';
			j++;
		}
	}
	long long ans=0;
	sort(a,a+j);
	if(a[j-1]==0)
	{
		cout<<0;
	}
	else
	for(int i=j-1;i>=0;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
