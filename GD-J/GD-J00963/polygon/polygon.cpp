#include<iostream>
#include<algorithm>
using namespace std;
int n,a[5005],p=1,q=1,minn,maxn,zhongjian;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	maxn=max(a[1],max(a[2],a[3]));
	minn=min(a[1],min(a[2],a[3]));
	for(int i=1;i<=3;i++)
	{
		if(maxn==a[i]&&p)p--;
		else if(minn==a[i]&&q)q--;
		else zhongjian=a[i];
	}
	if((zhongjian+minn)>maxn)cout<<1;
	else cout<<0;
	return 0;
}
