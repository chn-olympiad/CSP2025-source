#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size(),g=0;
	int l=len;
	for(int i=0;i<l;i++)
	{
		if(s[i]>=48&&s[i]<=57)
		{
			a[g++]=s[i]-48;
	//		cout<<a[i]<<endl;
		}
		else len--;
	}
	sort(a,a+len);
	for(int i=len-1;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}