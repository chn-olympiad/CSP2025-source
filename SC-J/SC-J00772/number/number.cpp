#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int nums,num[1000010];
string s;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<int(s.length());i++)
	{
		if(s[i]-'0'<=9 and s[i]-'0'>=0)
		{
			nums++;
			num[nums]=s[i]-'0';
		}
	}
	sort(num+1,num+nums+1);
	for(int i=nums;i>0;i--)
	{
		cout<<num[i];
	}
	return 0;
}