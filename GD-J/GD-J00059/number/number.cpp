#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int a[N];
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
	string s;
	cin>>s;
	int k=0;
	for(int i=0;i<s.length();i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			a[++k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1,cmp);
	for(int i=1;i<=k;i++)
	{
		cout<<a[i];
	}
	return 0;
}
