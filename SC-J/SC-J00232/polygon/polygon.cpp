#include<bits/stdc++.h>
using namespace std;
int n,a[5005],mmax,ans,s;
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mmax=max(mmax,a[i]);
		s+=a[i];
	}
	if(s>mmax*2) ans++;
	cout<<ans;
	return 0;
}