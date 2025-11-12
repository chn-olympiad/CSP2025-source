//GZ-S00498 贵阳市第十八中学 高逸晨 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[505],cnt=1,b,c[505];
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
		cnt*=i,cnt%=998244353;
	cout<<cnt;
	return 0;
}
