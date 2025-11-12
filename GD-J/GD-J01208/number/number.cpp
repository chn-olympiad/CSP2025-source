#include<bits/stdc++.h>
using namespace std;
string t;
int a[1000005],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=0;i<t.size();i++)
	{
		if(t[i]>='0'&&t[i]<='9')
		{
			a[++cnt]=t[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,greater<int>());
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
	return 0;
}
