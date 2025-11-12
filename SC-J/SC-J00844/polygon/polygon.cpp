#include <bits/stdc++.h>
using namespace std;

const int N=5001,M=998244353;
int n,s[N],ans;
/*int sum(int x,int d)
{
	if(x==0)return 0;
	if(d==3)return x;
	return (sum())
}*/

int main()
{
	freopen("polygon.in","cin",stdin);
	freopen("polygon.out","cin",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	if(n==3)
	{
		sort(s+1,s+n+1);
		if((s[1]+s[2])>s[3])
			cout<<1;
		else
			cout<<0;
	}
	else
		cout<<(n-1)*(n-2)/2;
	return 0;
}