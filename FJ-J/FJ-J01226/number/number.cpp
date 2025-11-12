#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int cnt;
int a[N];
string s;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';	
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++)
	{
		cout<<a[i];
	}
}
