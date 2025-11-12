#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int nums[1000];
	int numuse=0;
	int zifu[1000];
	for(int i=0;i<s.length();i++)
	{
		zifu[i]=s[i];
	}
	for(int i=0;i<s.length();i++)
	{
		if(zifu[i]>=48&&zifu[i]<=57)
		{
			nums[numuse]=zifu[i]-48;
			numuse++;
		}
	}

	for(int i=0;i<numuse;i++)
	{
		for(int j=i+1;j<numuse;j++)
		{
			if(nums[j]>nums[i])
			{
				swap(nums[j],nums[i]);
				
			}
		}
	}
	for(int i=0;i<numuse;i++)
	{
		cout<<nums[i];
	}
	
	return 0;


}
