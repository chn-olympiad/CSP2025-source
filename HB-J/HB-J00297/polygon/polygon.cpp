#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int n,a[5005],cnt,ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2)
	{
		cout<<0;
		return 0;
	}
	int p=n;
	while(p>=3)
	{
		int l=1,r=p;
		
		while(r<=n)
		{
			sort(a+l,a+r,cmp);
			for(int i=l;i<=r;i++)ans+=a[i];
			if(ans>a[l])cnt++;
			l++;
			r++;
		}
		p--;
	}
	cout<<cnt;
	return 0;
}
