#include<bits/stdc++.h>
using namespace std;
int pe[105];
int a[12][12];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m,R,rank;
	cin>>n>>m;
	cin>>pe[1];
	R=pe[1];
	for(int i=2;i<=n*m;i++)
	cin>>pe[i];
	sort(pe+1,pe+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(pe[i]==R)
	{
		rank=i;
		break;
	}
//	cout<<rank<<" ";
//	for(int i=1;i<=n*m;i++)
//	cout<<pe[i]<<" ";
	if(rank%n==0)
	{
		cout<<rank/n<<' ';
		if((rank/n)%2==0)
		cout<<1;
		else
		cout<<m;
	}
	else
	{
		cout<<rank/n+1<<' ';
		if((rank/n)%2==0)
		cout<<rank%n;
		else
		cout<<m-(rank%n)+1;
	}
	return 0;
}
