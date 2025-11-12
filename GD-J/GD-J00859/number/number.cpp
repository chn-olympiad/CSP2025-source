#include<bits/stdc++.h>
using namespace std;
string s;int a[15];bool ts=true;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9')a[s[i]-'0']++;
	for(int i=9;i>=1;i--)
		if(a[i]>0){ts=false;break;}
	if(ts){cout<<0;return 0;}
	for(int i=9;i>=0;i--)
	{
		if(a[i]==0)continue;
		for(int j=1;j<=a[i];j++)cout<<i;
	}
	return 0;
 } 
