#include<bits/stdc++.h>
using namespace std;
char s[1000100];
int num[1000100],top;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;(s[i]<='z'&&s[i]>='a')||(s[i]<='9'&&s[i]>='0');i++)
	{
		if(s[i]<='9'&&s[i]>='0')
		{
			top+=1;num[top]=(s[i]-'0');
		}
	}
	sort(num+1,num+top+1);
	for(int i=top;i>=1;i--)cout<<num[i];
	return 0;
}
