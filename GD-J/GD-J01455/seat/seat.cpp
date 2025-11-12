#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],x,p;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1];
	sort(a+1,a+1+n*m,cmp); 
	for(int i=1;i<=n*m;i++)
	if(a[i]==x)
	{
		x=i;
		break;
	}
	cout<<x/m+(x%m!=0)<<" ";
	if((x/m+(x%m!=0))%2) cout<<x%m+m*(x%m==0);
	else cout<<n-x%m+1;
	return 0;
}
