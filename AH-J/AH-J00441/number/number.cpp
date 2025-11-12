#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int u=s.size();
	int a[11]={0};
	for(int i=0;i<u;i++)
	{
		if(s[i]>='1' && s[i]<='9')
		{
			a[s[i]-'0']++;}
	}	
	for(int i=9;i>=1;i--)
	{
		for(int j=1;j<=a[i];j++)
		cout<<i;
	}
	
	return 0;
}
