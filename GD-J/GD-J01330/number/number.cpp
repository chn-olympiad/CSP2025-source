#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010],cnt=0;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0,j=1;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[j]=s[i]-'0';
			cnt++,j++;
		}
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
}
