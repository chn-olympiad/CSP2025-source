#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
char c;
int a[N],n;
signed main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(cin>>c)
	{
		if(c>='0'&&c<='9')
		{
			a[++n]=c-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
