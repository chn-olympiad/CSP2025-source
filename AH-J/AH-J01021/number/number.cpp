#include<bits/stdc++.h>
using namespace std;

long long num[10];

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<=n;i++)
	{
		int temp=s[i]-'0';
		if(temp>=0 && temp<=9)
		{
			num[temp]++;
		}
	}

	for(int i=9;i>=0;i--)
	{
		for(long long j=0;j<num[i];j++)
		{
			cout<<i;
		}
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
