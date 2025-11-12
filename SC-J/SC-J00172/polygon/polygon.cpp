#include<bits/stdc++.h>
using namespace std;
int a[5010],sum=0,cnt=0,maxr=-1,n;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		maxr=max(maxr,a[i]);
		sum+=a[i];
	}
	if(sum>2*maxr)
	{
		cnt++;
	}
	cout<<cnt;
	return 0;
}