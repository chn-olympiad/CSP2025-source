#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5;
int n,cnt,a[N];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[++cnt]=s[i]-'0';
			a[cnt]=-a[cnt];
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=1;i<=cnt;i++)
	{
		a[i]=-a[i];
		cout<<a[i];
	}
	return 0;
}
