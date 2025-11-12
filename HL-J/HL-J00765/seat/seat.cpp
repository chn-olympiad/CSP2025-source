#include <bits/stdc++.h> 
using namespace std;
int a[105];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,ls=0;
	cin>>n>>m;
	cin>>a[1];
	int x=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]>=a[1])cnt++;
	}
	if(cnt%n==0)
	{
		cout<<cnt/n<<" ";
	}
	else if(cnt%n!=0)
	{
		cout<<cnt/n+1<<" ";
	}
	if(cnt%n==0)
	{
		ls=cnt/n;
	}
	else if(cnt%n!=0)
	{
		ls=cnt/n+1; 
	}
	int ys=cnt%n;
	if(ys==0)ys=n;
	if(ls%2==1)cout<<ys; 
	else cout<<n-ys+1;
	return 0;
} 
