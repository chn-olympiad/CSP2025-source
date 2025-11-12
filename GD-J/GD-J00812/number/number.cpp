#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s,ans;
	int nums[1000005],k=0;
	cin >> s;
	for (int i=0;i<s.length();i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			nums[k]=(int)s[i];
			k++;
		}
	}	
	sort(nums,nums+k);
	for (int j=k-1;j>=0;j--)
		ans+=(char)nums[j];
	cout << ans;
	return 0;
}
