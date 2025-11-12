#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a[10]={0};
	for(int i=0;i<=s.size();i++)
	{
		if(s[i]-'0'>=0&&s[i]-0<='9')
			a[s[i]-'0']+=1;
	}
	for(int i=9;i>=0;i--)
	{
		while(a[i]>0)
		{
			cout<<i;
			a[i]--;
		}
	}
	return 0;
}
