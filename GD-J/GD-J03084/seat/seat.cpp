#include<bits/stdc++.h>
using namespace std;
int n,m,a[500];
int GG_Bound(int l,int r,int x)
{
	int GG=0;
	while(l<=r)
	{
		int Bound=(l+r)>>1;
		if(a[Bound]>=x)
		{
			GG=Bound;
			l=Bound+1;
		}
		else
		{
			r=Bound-1;
		}
	}
	return GG;
}
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int h=a[1];
	sort(a+1,a+1+n*m,cmp);
	int pos=GG_Bound(1,n*m,h);
	int ans1,ans2;
	ans1=pos/n+(pos%n!=0);
	pos=pos%n;
	if(pos==0)
	{
		ans2=(ans1%2==0)?1:n;
	}
	else
	{
		ans2=(ans1%2==0)?(n-pos+1):pos;
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}
