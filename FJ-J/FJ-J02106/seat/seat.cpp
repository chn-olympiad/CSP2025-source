#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,m,a[N],xv;
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	xv=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==xv)
		{
//			cout<<i<<' ';
			i=n*m-i+1;
			int pai=ceil(i*1.0/n),lie=i%n;
			if(lie==0)lie=n;
			cout<<pai<<' ';
			if(pai%2)cout<<lie<<' ';
			else cout<<n-lie+1<<' ';break;
		}
	}
	return 0;
}
