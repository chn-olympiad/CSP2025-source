#include<bits/stdc++.h>
using namespace std;
int cmp(int x,int y)
{
	return x<y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	long long a[100005]={};
	
	long long sum=0;
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[sum]=s[i]-'0';
			sum++;
		}
	}
	sort(a,a+sum,cmp);
	for(int i=sum-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
