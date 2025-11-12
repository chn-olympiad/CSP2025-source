#include <bits/stdc++.h>
using namespace std;
int num[1000005],idx=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for (unsigned int i=0;i<s.size();i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			num[idx]=(s[i]-'0');
			idx++;
		}
	}
	sort(num+1,num+idx);
	for (int i=idx-1;i>=1;i--)
	{
		printf("%d",num[i]);
	}
	return 0;
}
