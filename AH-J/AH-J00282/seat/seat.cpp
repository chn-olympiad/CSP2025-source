#include<bits/stdc++.h>
using namespace std;
long long m,n;
struct xs{
	long long z,id;
}a[1005];
bool cmp(xs x,xs y)
{
	return x.z>y.z;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i].z;
		a[i].id=i;
	}
	long long t=-1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i].id==1)
		{
			t=i;
		}
	}
	long long xx=t/n,yy=t%n;
	if(yy==0)
	{
		if(xx%2==0)
			cout<<xx<<" "<<1;
		else
			cout<<xx<<" "<<n;
	}
	else
	{
		if((xx+1)%2==0)
			cout<<xx+1<<" "<<n-yy+1;
		else
			cout<<xx+1<<" "<<yy;
	}//1 3
	return 0;
}
