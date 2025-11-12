#include<bits\stdc++.h>
using namespace std;
int n,m;
int x,ai,oi;
int ans1,ans2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1) cin>>ai,x++;
			else
			{
				cin>>oi;
				if(oi>ai) x++;
			}
		}
	if(x%n==0)
	{
		ans1=x/n;
		if((x/n)%2==0) ans2=1;
		else ans2=n; 
	}
	else
	{
		ans1=x/n+1;
		if(ans1%2==0)
			ans2=n-(x%n)+1;
		else
			ans2=x%n;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
