#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int t = 0;
	int l = s.size();
	for (int i = 0;i<l;i++)
	{
		if (s[i]-'0'>=0&&s[i]-'0'<10)
		{
			t++;
			a[t]=s[i]-'0';
		}
	}
	sort(a+1,a+t+1,cmp);
	for (int i = 1;i<=t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
