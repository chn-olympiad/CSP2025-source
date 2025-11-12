#include<bits/stdc++.h>
using namespace std;

// I love zll;

string s;
char nums[1000005];
int now=0;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>=48 && s[i]<=57)
		{
			now++;
			nums[now]=s[i];
		}
	}
	sort(nums+1,nums+1+now);
	for(int i=now;i>=1;i--)
	{
		cout<<nums[i];
	}
	return 0;
}
