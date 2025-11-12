#include<bits/stdc++.h>
using namespace std;
int m[1000005];
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	int cnt=0;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0' and s[i]<='9')
		{
			m[cnt++]=int(s[i])-48;
		}
	}
	sort(m,m+cnt,cmp);
	for(int i=0;i<cnt;i++)
	{
		cout<<m[i];
	}
	return 0;
}
