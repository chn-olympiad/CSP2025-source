#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
string s;
int a[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int t=1;
	for (int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			a[t]=s[i]-'0';
			t++;
		}
	}
	int sum=0;
	sort(a,a+t,cmp);
	for (int i=t;i>0;i--)
	{
		for (int j=0;j<i;j++)
		{
			if (i==1) sum+=a[i];
			else sum+=a[i]*10;
		}
	} 
	cout<<sum;
	return 0;
}
