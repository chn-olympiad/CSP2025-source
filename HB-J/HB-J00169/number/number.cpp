#include <bits/stdc++.h>
using namespace std;
string a;
int cnt=0,res=0,b[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]>='0' && a[i]<='9')
		{
			cnt++;
			b[cnt]=a[i]-'0';
		}
	}
	sort(b+1,b+1+cnt,cmp);
	if(b[1]==0)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt;i++)
	{
		cout<<b[i];
	}
	return 0;
}
