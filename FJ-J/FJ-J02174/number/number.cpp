#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000005];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string str;
	int cnt=0;
	cin>>str;
	for(int i=1;i<=str.size();i++)
	{
		if(str[i-1]<='9'&&str[i-1]>='0')
		{
			a[++cnt]=str[i-1]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(a[1]==0)
		cout<<0;
	else{
		for(int i=1;i<=cnt;i++)
			cout<<a[i];
	}
}
