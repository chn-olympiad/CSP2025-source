#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[400005],m,r,dis;
int l,h;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==r)
		{
			dis=n*m-i+1;
			break;
		}
	}
	l=dis/n;
	dis=dis%n;
	if(dis!=0) 
	{
		l++;
		if(l%2==1) h=dis;
		else h=n-dis+1;
	}
	else
		h=n;
	cout<<l<<" "<<h<<"\n";
	return 0;
}