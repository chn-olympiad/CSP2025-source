#include<bits/stdc++.h>
using namespace std;
int a[10];
string s;
int main()
{
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(long long i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9') a[s[i]-48]++;
	}
	for(int i=9;i>=0;i--)
	{
		for(;a[i]>0;a[i]--)
			cout<<i;
	}
	return 0;
}