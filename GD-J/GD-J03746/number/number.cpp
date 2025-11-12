#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++)
	{
		for(int j=0;j<10;j++)
		{
			if(s[i]-'0'==j)
			{
				a[j]++;
				break;
			}
		}
	}
	int num=9;
	while(num!=-1)
	{
		if(a[num]!=0)
		{
			cout<<num;
			a[num]--;
		}
		else
		{
			num--;
		}
	}
	return 0;
}
