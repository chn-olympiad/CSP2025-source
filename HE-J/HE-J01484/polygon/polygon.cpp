#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[5100];
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if (n<=2)
	{
		cout<<0<<endl;
		return 0;
	}else if (n==3){
		int sum=0;
		int maxn=-110000;
		for (int i=1;i<=n;i++)
		{
			sum+=a[i];
			maxn=max(maxn,a[i]);
		}
		if (sum>2*maxn)
		{
			cout<<1<<endl;
			return 0;
		}else{
			cout<<0<<endl;
			return 0;
		}
	}else if (n==4){
		int tot=0;
		int sum1=a[1]+a[2]+a[3],maxn1=max(a[1],max(a[2],a[3]));
		int sum2=a[1]+a[2]+a[4],maxn2=max(a[1],max(a[2],a[4]));
		int sum3=a[2]+a[3]+a[4],maxn3=max(a[2],max(a[3],a[4]));
		if (sum1>2*maxn1)
		{
			tot++;
		}
		if (sum2>2*maxn2)
		{
			tot++;
		}
		if (sum3>2*maxn3)
		{
			tot++;
		}
		cout<<tot<<endl;
		return 0;
	}
	return 0;
}
