#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N=1e5+10;
int n,m,a[N],x,y=0;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>x;
	for(int i=2;i<=n*m;i++)
	{
		cin>>a[i];
		if(a[i]>x)y++;
	}
	int z=y%n;
	if((y/n)%2==0)
	{
		cout<<(y/n)+1<<" "<<1+z; 
	}
	else
	{
		cout<<(y/n)+1<<" "<<n-z;
	}
	return 0;
}
