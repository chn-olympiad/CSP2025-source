#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[150];
ll h,n,m,k=0,r=1;
void solve(ll x,ll y) {cout<<x<<" "<<y;exit(0);}
bool cmp(ll x,ll y) {return x>y;}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if (i==1) h=a[i];
	}
	sort(a+1,a+n*m+1,cmp);
	for (int c=1;c<=m;c++)
	{
		k++;
		if (a[k]==h) solve(c,r);
		if (c%2==1)
		while (r<n)
		{
			r++;
			k++;
			if (a[k]==h) solve(c,r);
		}
		else
		while (r>1)
		{
			r--;
			k++;
			if (a[k]==h) solve(c,r);
		}
	}
	return 0;
}
