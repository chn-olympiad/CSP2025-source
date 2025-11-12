#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
const int p=998244353;
int n,a[5005],t[5005];
int jc(int m)
{
	int s=1;
	for(int i=2;i<=m;i++)
	{
		s*=i;
		s%=p;
	}
	return s;
}
signed main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n<=3)
	{
		sort(a+1,a+4);
		if(a[1]+a[2]+a[3]>2*a[3]) cout<<1;
		else cout<<0;
	}
	else
	{
		int s=0,nc=jc(n);
		for(int i=3;i<=n;i++)
		{
			s+=nc/((jc(i)*jc(n-i))%p);
			s%=p;
		}
		cout<<s;
	}
	
	return 0;
}
