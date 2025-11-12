#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=s.size();
	
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			a[sum]=s[i];
			sum++;
		}
	}
	sort(a,a+sum);
	for(int i=sum-1;i>=0;i--)
	{
		cout<<char(a[i]);
	}
	return 0;
}

