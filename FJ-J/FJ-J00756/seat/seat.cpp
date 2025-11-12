#include <bits/stdc++.h>
using namespace std;

int n,m,l,r,mid,c,h,cnt;
int a[105];
bool cmp(int x, int y)
{
	return x>y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n*m; i++)
		cin>>a[i];
		
	cnt=a[1];
	l=1;
	r=n*m;
	sort(a+1,a+1+n*m,cmp);
	while(l <= r)
	{
		mid=(l+r)/2;
		if(a[mid] == cnt)
			break;
		else if(a[mid] < cnt)
			r=mid-1;
		else
			l=mid+1;
	}
	
	if(mid%n != 0)
		c=mid/n+1;
	else
		c=mid/n;
		
	if(c%2 == 0)
		h=n-mid%n+1;
	else
		h=1+(mid-1)%n;
		
	cout<<c<<" "<<h;
	
	return 0;
}
