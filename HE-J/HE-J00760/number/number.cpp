#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
string s;
int a[N];
int cnt;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	int n=s.size();
	for (int i=0;i<n;i++)
	{
		if ('0'<=s[i] && '9'>=s[i]) 
		{
			a[i]=s[i]-'0';
			cnt++;
		}
	}
	sort(a,a+n,cmp);
	for (int i=0;i<cnt;i++) printf("%d",a[i]);
	return 0;
}
