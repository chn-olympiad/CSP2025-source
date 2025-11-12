#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000010],cnt;
bool pd;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
			if(a[cnt]!=0) pd=true;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	if(!pd) cout<<"0";
	else
	{
		for(int i=1;i<=cnt;i++)
		{
			cout<<a[i];
		}
	}
	return 0;
}
