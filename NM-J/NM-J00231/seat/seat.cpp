#include<bits/stdc++.h>
#define int long long
#define N 1005
using namespace std;

struct str
{
	int x;
	int id;
}a[N];

int n,m;
int cnt;
array<array<int,N>,N> p;

signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		scanf("%lld",&a[i].x);
		a[i].id=i;
	}
	
	sort(a+1,a+1+n*m,[](str &l,str &r)
	{return l.x>r.x;});
	
	for(int i=1;i<=n;i++)
	{
		if(i&1)
		for(int j=1;j<=m;j++)
		p.at(j).at(i)=a[++cnt].id;
		else
		for(int j=m;j>=1;j--)
		p.at(j).at(i)=a[++cnt].id;
	}
	
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	if(p.at(i).at(j)==1)
	{
		cout<<j<<' '<<i<<endl;
		return 0;
	}

	cout<<"1 1";
	//	?
	return 0;
}
