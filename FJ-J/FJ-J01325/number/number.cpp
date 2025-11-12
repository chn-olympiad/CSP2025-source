#include <bits/stdc++.h>
using namespace std;
string n;
long long a[1000006],sum,num,ans,kpl;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.length();i++)
	{
		if(n[i]>='0'&&n[i]<='9')
		{
			a[i]=n[i]-'0';
			if(a[i]==0)
			{
				num++;
			}
		}
		else
		{
			kpl++;
		}
	}
	sort(a,a+n.length(),cmp);
	for(int i=0;i<n.length()-kpl;i++)
	{
		if(a[i]!=0)
		{
			sum+=pow(10,n.length()-kpl-i-1)*a[i];
		}
		else
		{
			if(ans<num)
			{
				sum+=pow(10,n.length()-kpl-i-1)*a[i];
				ans++;
			}
		}
	}
	cout<<sum;
	return 0;
}