#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+10;

ll n,m,h,a[N],d;
ll x=1,y=1,f,dy[10];

bool cmp(ll x,ll y)
{
	return x > y;
}

int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	h=n*m;
	dy[0]=1;
	dy[1]=-1;
	for(int i=1;i<=h;i++)
	{
		cin >> a[i];
	}
	d=a[1];
	sort(a+1,a+h+1,cmp);
	
	for(int i=1;i<=h;i++)
	{
		if(a[i]==d)
		{
			cout << x << " " << y << endl;
		}
		
		ll Y=y+dy[f];
		if(Y>=1 && Y<=n)
		{
			y=Y;
		}
		else
		{
			x++;
			f^=1;
		}
	}
	return 0;
}