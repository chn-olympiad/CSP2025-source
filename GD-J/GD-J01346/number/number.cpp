#include<bits/stdc++.h>
using namespace std;
string s;
int k;
int d[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int len=s.size();
	for(int i=0; i<len; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			d[++k]=s[i]-48;
		}
	}
	sort(d+1,d+k+1,cmp);
	for(int i=1; i<=k; i++)
	{
		printf("%d",d[i]);
	}
	return 0;
}
