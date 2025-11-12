#include<bits/stdc++.h>
using namespace std;
long long t,n,m,s;
struct sut
{
	long long x,y,xs,ys;
}a[110000];
struct sat
{
	long long x,h;
}st[4],sx[3],b[110000];
bool cmp(sat px,sat py)
{
	return px.x>py.x;
}
void workrun()
{
	sx[1].x=0;
	sx[2].x=0;
	sx[3].x=0;
	sx[1].h=1;
	sx[2].h=2;
	sx[3].h=3;
	s=0;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>st[1].x>>st[2].x>>st[3].x;
		st[1].h=1;
		st[2].h=2;
		st[3].h=3;
		sort(st+1,st+4,cmp);
		a[i].x=st[1].h;
		sx[st[1].h].x++;
		a[i].xs=st[1].x;
		a[i].y=st[2].h;
		a[i].ys=st[2].x;
	}
	sort(sx+1,sx+4,cmp);
	m=0;
	for(long long i=1;i<=n;i++)
	{
		s+=a[i].xs;
		if(a[i].x==sx[1].h)
		{
			m++;
			b[m].x=a[i].ys-a[i].xs;
			b[m].h=a[i].xs;
		}
	}
	sort(b+1,b+m+1,cmp);
	for(long long i=1;i<=m-n/2;i++)
	{
		s+=b[i].x;
	}
	cout<<s<<endl;
	return;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		workrun();
	}
	return 0;
}
