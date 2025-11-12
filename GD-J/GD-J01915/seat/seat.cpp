#include<bits/stdc++.h>
using namespace std;
int n,m,t,k=1,q,x=1,y=1,sx,a[10005];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	t=a[1];
	sort(a+1,a+1+n*m);
	for(int i=n*m;i>=1;i--) if(a[i]==t) q=n*m-i+1;
	while(k!=q)
	{
		if(sx==0&&y==n) x++,sx=1;
		else if(sx==1&&y==1) x++,sx=0;
		else if(sx==0) y++;
		else if(sx==1) y--;
		k++;
	}
	cout<<x<<" "<<y;
}

