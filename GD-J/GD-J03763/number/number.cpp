#include<iostream>
#include<cstdio>
using namespace std;
string s;
int sum[20];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')
			sum[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(sum[i]--)
			cout<<i;
	return 0;	
} 
