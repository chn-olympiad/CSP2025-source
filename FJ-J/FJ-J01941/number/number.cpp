#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;cin>>s;
	int num[10];
	for(int i=0;i<=9;i++)num[i]=0;
	for(int i=0;i<s.size();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
			num[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
	{
		//cout<<num[i]<<' ';
		for(int j=1;j<=num[i];j++)cout<<i;
	}
	return 0;
}
