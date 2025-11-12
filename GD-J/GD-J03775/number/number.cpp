#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","s",stdin);
	freopen("number.out","w",stdout);
	char s[10000000001];
	int a[10000000001];
	int sum = 0;
	for(int i = 1;i <= 10000000001;i++)
	{
		int j = 1;
		while(cin>>s[i])
		{
			if(s[i] >= '0' && s[i] <= '9')
			{
				s[i] += a[j];
				s[i]++;
				a[j+1];
				sum++;
			}
		}
	}
	for(int i = 1;i <= sum;i++)
	{
		while(a[i] > a[i-1])
		{
			swap(a[i],a[i-1]);
		}
	}
	for(int i = 1;i <= sum;i++)
	{
		cout<<a[i];
	}
	return 0;
}
