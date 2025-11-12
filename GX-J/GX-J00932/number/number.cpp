#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,nums="";
	cin>>s;
	for(char c:s)
	{
		if(c>='0'&&c<='9')
		{
			nums+=c;
			}
		}
		sort(nums.begin(),nums.end(),greater<char>());
		cout<<nums;
	return 0;
}
