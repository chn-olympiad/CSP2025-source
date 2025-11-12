#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	vector<int> nums;
	while(!s.empty())
	{
		if(s.front()=='0' || s.front()=='1' || s.front()=='2' || s.front()=='3' || s.front()=='4' || s.front()=='5' || s.front()=='6' || s.front()=='7' || s.front()=='8' || s.front()=='9')
		{
			nums.push_back(s.front());
		}
		s.pop_back();
	}
	sort(nums.begin(),nums.end());
	int end1;
	for(int i=nums.size();i>0;i--)
	{
		end1=i*nums.size()*10;
	}
	end1=end1+nums[0];
	cout<<end1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
