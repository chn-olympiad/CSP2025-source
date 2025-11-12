#include <bits/stdc++.h>
using namespace std;

int n,m,aj,anj;
int a[110];
bool qqq(int x,int y){
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	aj=a[1];
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n*m,qqq);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==aj)
		{
			anj=i;
			break;
		}
	}
	cout<<anj/n+(bool)(anj%n)<<' ';
	int ak=(anj/n+(bool)(anj%n)-1)*n;
	if((anj/n+(bool)(anj%n))%2==1)
	{
		cout<<anj-ak;
	}
	else cout<<n-(anj-ak)+1;
	return 0;
}
