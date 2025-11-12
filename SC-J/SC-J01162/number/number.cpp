#include<bits/stdc++.h>
using namespace std;
long long m,n[10000000],cnt;
string s;
bool cmp(long long x,long long y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	m=s.size();
	for(long long i=0;i<m;i++)
	{
		if(('0'<=s[i])and (s[i]<='9'))
		{
			n[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(n,n+m,cmp);
	for(long long i=0;i<cnt;i++)
	{
		cout<<n[i];
	}
	return 0;
}