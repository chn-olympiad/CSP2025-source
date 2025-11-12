#include<bits/stdc++.h>
using namespace std;
int n,a[10000],ans,maxa=INT_MIN,cnt;
int main()
{
	freopen("polygon,in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==3)
	{
		for(int i=1;i<=n;i++)
		{
			maxa=max(maxa,a[i]);
			cnt+=a[i];
		}
		if(cnt>2*maxa)
		{
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
