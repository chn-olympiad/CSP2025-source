#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[114],n,m;
bool cmp(int x,int y) {
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i)
	{
		cin>>a[i];
	}
	int R=a[1];
	sort(a+1,a+1+n*m,cmp);
	int s=0; 
	for(int i=1;i<=n*m;++i)
	{
		if(R==a[i])
		{
			s=i;
			break;
		}
	}
	int h=s/n,l=s%n;
	if(h%2)
	{
		if(l==0)
		{
			cout<<h<<" "<<n-l;
		}
		else
		{
			cout<<h+1<<" "<<n-l+1;
		}
	}
	else 
	{
		if(l==0)
		{
			cout<<h<<" "<<n-l;
		}
		else
		{
			cout<<h+1<<" "<<l;
		}
	}
	return 0;
 } 
//FUCK CCF