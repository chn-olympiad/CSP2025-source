#include <bits/stdc++.h>
using namespace std;
const int N=18;
int n,m,val;
int a[N*N];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	val=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1,l=1,r=1;i<=n*m;i++)
	{
		//cout<<i<<" "<<l<<" "<<r<<'\n';
		if(a[i]==val)
		{
			cout<<l<<" "<<r;
			break;
		}
		if(l%2==1)
		{
			if(r==m) l++;
			else r++;
		}
		else if(l%2==0)
		{
			if(r==1) l++;
			else r--;
		}
	}
	return 0;
}