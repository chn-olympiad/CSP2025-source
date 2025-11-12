#include <bits/stdc++.h>
using namespace std;
const int N=1000010;
int a[N],n=0;
string s;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(int(s[i])<=48||int(s[i])<=57)
		{
			a[n++]=s[i]-'0';
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)cout<<a[i];
	return 0;
}
