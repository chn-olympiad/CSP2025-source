#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000011];
int k;
inline bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i(0);i<l;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++k]=s[i]-48;
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i(1);i<=k;i++)
	{
		cout<<a[i];
	}
	return 0;
}
