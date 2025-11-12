#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+50;
int a[N];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int t=n*m;
	for(int i=1;i<=t;++i)cin>>a[i];
	int id=a[1],x=0,y=1;
	for(int i=1;i<t;++i)
	{
		for(int j=i+1;j<=t;++j)
		{
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	bool f=0;
	for(int i=1;i<=t;++i)
	{
		if((x==n&&y%2!=0)||(x==1&&y%2==0)) f=1;
		if(f==1) ++y;
		if(x<n&&y%2==1)
		{
			if(f==1) f=0;
			else ++x;
		}
		else 
		{
			if(f==1)f=0;
			else --x;
		}
		if(id==a[i])
		{
			cout<<y<<" "<<x;
			return 0;
		}
	}
	return 0;
}
