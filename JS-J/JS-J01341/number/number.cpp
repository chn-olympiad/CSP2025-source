#include<bits/stdc++.h>
using namespace std;
int sum=0,a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len;
	len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum++;
			a[sum]=s[i]-'0';
		}
	}
	sort(a+1,a+sum+1);
	for(int i=sum;i>=1;i--)
	{
		cout<<a[i];
	}	
	return 0;
}
