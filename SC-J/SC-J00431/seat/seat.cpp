#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
const int N=21;
int n,m,tot,a[N*N],b,ind,r,c;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	IOS;
	cin>>n>>m;
	tot=n*m;
	for(int i=1;i<=tot;i++)
		cin>>a[i];
	b=a[1];
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++)
		if(a[i]==b) ind=i;
	if(ind%n==0)
	{
		r=ind/n;
		if(r&1) c=n;
		else c=1;
	}
	else
	{
		r=(ind/n)+1;
		if(r&1) c=ind%r;
		else c=n-(ind%r)+1;
	}
	cout<<r<<' '<<c<<'\n';
	return 0;
}