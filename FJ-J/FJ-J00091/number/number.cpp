#include<bits/stdc++.h>
using namespace std;
int o[10]={0};
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]<='9')
		{
			o[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(o[i]>0)
		{
			cout<<i;
			o[i]--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
