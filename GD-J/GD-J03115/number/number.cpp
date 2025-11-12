#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[10];
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size(),i;
	for(int i=0;i<l;i++)
	{
		if(s[i]<='9'&&s[i]>='0')
			a[s[i]-'0']++;
	}
	for(int i=9;i>=0;i--)
		for(int j=1;j<=a[i];j++)
			printf("%lld",i);
	return 0;
}

