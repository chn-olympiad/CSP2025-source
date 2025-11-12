#include <iostream>
using namespace std;

long long cnt = 0;
int a[114514];
long long C(int n,int m)
{
	long long x = 1;
	for(int i = 2;i<=n;i++)x*=i;
	for(int i = 2;i<=n-m;i++)x/=i;
	for(int i = 2;i<=m;i++)x/=i;
	return x;
}

int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n<3)
	{
		cout<<0;
		return 0;
	}
	for(int i = 1;i<=n;i++)cin>>a[i];
	if(n==3)
	{
		int mx = max(a[1],max(a[2],a[3]));
		if(mx==a[1]&&a[2]+a[3]>a[1])cout<<1;
		else if(mx==a[2]&&a[1]+a[3]>a[2])cout<<1;
		else if(mx==a[3]&&a[2]+a[1]>a[3])cout<<1;
		else cout<<0;
		return 0;
	}
	for(int i = 3;i<=n;i++){cnt+=C(n,i);}
	cout<<cnt%998244353;
	return 0;
}
//%%%图灵之神%%%
//%%%冯·诺依曼之神%%%
//%%%%%%%%%%%%%%%%%%%%
//佑我此题36分 
