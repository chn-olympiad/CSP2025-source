#include <bits/stdc++.h>
using namespace std;
long long int a[1000000+10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long int j=1,ans=0,m;
	cin>>s;
	m=s.length();
	for(long long int i=0;i<m;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i]-'0';
			
			j++;
		}
	}
	j--;
	sort(a+1,a+j+1);
	reverse(a+1,a+j+1);
	for(long long int i=1;i<=j;i++)
	{
		cout<<a[i]; 
	}
	return 0;
 } 
