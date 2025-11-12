#include<bits/stdc++.h>
using namespace std;
int n,m,a[101];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int s=a[1],f=1;
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--) if(a[i]==s) f=n*m-i+1;
	for(int i=1;i<=m;i++)
	{
		if(f>(i-1)*n&&f<=i*n)
		{
			if(i%2==1) cout<<i<<" "<<f-n*(i-1);
			else cout<<i<<" "<<n-(f-(i-1)*n)+1;
			break;
		}
	}
	return 0;
}
