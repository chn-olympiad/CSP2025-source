#include<bits/stdc++.h>
using namespace std;
int num[1000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int l,cnt=0;
	string s;
	cin>>s;
	l=s.size();
	s=" "+s;
	for (int i=1;i<=l;i++)
	{
		if (s[i]>='0'&&s[i]<='9')
		{
			cnt++;
			num[cnt]=(s[i]-'0');
		}
	}
	sort(num+1,num+cnt+1,greater<int>());
	for (int i=1;i<=cnt;i++)
	{
		printf("%d",num[i]);
	}
	return 0;
}
