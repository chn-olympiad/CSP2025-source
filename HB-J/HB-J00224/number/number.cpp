#include<bits/stdc++.h>
using namespace std;
int ans=0,a[11]={0};
string s;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;	
	int b=s.size();
	for(int i=0;i<b;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		for(int j=0;j<a[i];j++)	
		{
			ans=ans*10+i;
		}
	}
	cout<<ans;
}
