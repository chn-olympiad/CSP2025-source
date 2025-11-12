#include<bits/stdc++.h>
using namespace std;
string s,nums;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(isdigit(s[i]))
		{
			nums.push_back(s[i]);
		}
	}
	sort(nums.begin(),nums.end());
	for(int i=nums.size()-1;i>=0;i--)
	{
		cout<<nums[i];
	}
	return 0;	
} 