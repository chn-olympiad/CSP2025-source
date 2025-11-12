#include <bits/stdc++.h>
using namespace std;
const int N=1e6+6;
string s;
int a[N],cnt;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int ls=s.size();
	for (int i=0;i<ls;i++)
	{
		if (s[i]>='0' && s[i]<='9')
		{
			a[++cnt]=s[i];
		}
	}
	sort(a+1,a+cnt+1);
	for (int i=cnt;i>=1;i--)
	cout<<a[i]-'0';
	return 0;
}
