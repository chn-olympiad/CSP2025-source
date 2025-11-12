#include<bits/stdc++.h>
using namespace std;
int n,m,a[15][15],b[105],r,rn;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>b[i];
	r=b[0];
	sort(b,b+n*m);
	for(int i=0;i<n*m;i++)
	{
		if(b[i]==r)
		{
			rn=n*m-i;
			break;
		}
	}
	if((rn-1)/n%2==0)cout<<(rn-1)/n+1<<" "<<(rn-1)%n+1;
	if((rn-1)/n%2==1)cout<<(rn-1)/n+1<<" "<<n-(rn-1)%n;
	return 0;
} 
