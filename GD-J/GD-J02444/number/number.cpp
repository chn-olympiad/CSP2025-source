#include <bits/stdc++.h>
#define long long int;
using namespace std;
const int N=1e6+10;
string s;
int num[N];
int m;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num[++m]=s[i]-'0';
		}
	}
	sort(num+1,num+m+1);
	while(num[m]==0&&m>1)
	{
		m--;
	}
	for(int i=m;i>=1;i--)
	{
		cout<<num[i];
	}
	return 0;
}
