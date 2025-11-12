#include<bits/stdc++.h>
using namespace std;
int num[15];//0~9
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			num[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(num[i]--)
		{
			cout<<i;
		}
	}
	return 0;
} 
