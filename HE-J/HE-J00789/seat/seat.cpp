#include<bits/stdc++.h>
using namespace std;
int n,m,num,a[1000],cntx,cnty=1,pd=1;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	num=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
	{
		cntx+=pd;
		if(cntx>n)
		{
			cntx=n;
			pd=-1;
			cnty++;
		}
		if(cntx<1)
		{
			cntx=1;
			pd=1;
			cnty++;
		}
		if(a[i]==num)
		{
			cout<<cnty<<" "<<cntx;
			return 0;
		}
	}
	return 0;
}
