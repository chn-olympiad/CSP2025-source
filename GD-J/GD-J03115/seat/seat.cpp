#include<bits/stdc++.h>
using namespace std;
//#define int long long
int a[105];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1,cmp);
	int ans;
//	for(int i=1;i<=n*m;i++)
//		cout<<a[i]<<' ';
	for(ans=n*m;ans>=1;ans--)
		if(a[ans]==s)
			break;
	int ansx,ansy=1;
	if(ans%n==0)
		ansx=ans/n;
	else
		ansx=ans/n+1;
	if(ansx%2)
		ansy=ans%n;
	else
		ansy=n-ans%n+1;
	if(ansy==0)
	{
		if(ansx%2)
			ansy=n;
		else
			ansy=1;
	}
//	cout<<ans<<endl;
	cout<<ansx<<' '<<ansy;
	return 0;
}

