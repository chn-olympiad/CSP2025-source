#include<bits/stdc++.h>
using namespace std;
int num[1000005],tot;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[++tot]=s[i]-'0';
		}
	}
	sort(num+1,num+tot+1);
	for(int i=tot;i>=1;i--)
	{
		printf("%d",num[i]);
	}
	return 0;
}