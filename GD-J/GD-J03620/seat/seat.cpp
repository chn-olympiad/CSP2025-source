#include<iostream>
#include<vector>
using namespace std;
vector<int> a(110,0);
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt=0,x=-1,y=-1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	for(int i=1;i<=n*m;i++) if(a[i]>=a[1]) cnt++;
	if(cnt%n==0) x=cnt/n;
	else x=cnt/n+1;
	cout<<x<<" ";
	if(x%2==1)
	{
		y=cnt%n;
		if(y==0) y+=n;
	}
	else
	{
		y=cnt%n;
		if(y==0) y+=n;
		y=n-y+1;
	}
	cout<<y;
	return 0;
}
