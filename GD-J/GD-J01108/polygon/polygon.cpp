#include<bits/stdc++.h>
using namespace std;
int a[5010],ans;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,maxx=-1,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(sum>maxx*2)
		ans++;
	cout<<ans<<'\n';	
	return 0;
}
