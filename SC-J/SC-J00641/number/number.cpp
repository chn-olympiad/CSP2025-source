#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int lens = s.size(),box[100] = {};
	for(int i = 0;i<lens;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			box[s[i]]++;
		}
	}
	for(int i = 57;i>=48;i--)
	{
		for(int j = 1;j<=box[i];j++)
		{
			cout<<char(i);
		}
	}
	return 0; 
 } 