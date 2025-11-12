#include<bits/stdc++.h>
using namespace std;
string s;
long long a[10];
int sum[10][5000];
long long cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i = 0;i<=s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[s[i]-'0']++;
			cnt++;
		}
	}
	for(int i = 9;i>=0;i--)
	{
		sum[i][1] = i;
		sum[i][2] = a[i];
		
	}
	for(int i = 9;i>=0;i--)
	{
		for(int j = 1;j<=sum[i][2];j++)
		{
			cout<<i;
		}
	}
	return 0;
} 
