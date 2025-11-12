#include<bits/stdc++.h>
using namespace std;
const int N=1007;
int n,m;
int a[N];
int cnt=1;
int ans1,ans2;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	cin>>a[i];
	for(int i=2;i<=n*m;i++)
	{
		if(a[i]>a[1])
		cnt++;
	}
	int xx=cnt/n;
	if(cnt%n==0)
	ans2=xx;
	else
	ans2=xx+1;
	int yy=cnt%n;
	if(yy==0)
	{	
		if(xx%2==0)
		ans1=1;
		else
		ans1=n;
	}
	else
	{
		if(ans2%2)
		ans1=yy;
		else
		ans1=n-yy+1;
	}
	cout<<ans2<<' '<<ans1;
	return 0; 
}
