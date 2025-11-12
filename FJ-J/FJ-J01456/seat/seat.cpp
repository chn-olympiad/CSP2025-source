#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[1005],num,cnt=0,x=1,y=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i];
	num=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for (y=1;y<=m;y++)
	{
		if(y%2==1) for (x=1;x<=n;x++) 
		{
			cnt++;
			if(a[cnt]==num)
			{
				cout<<y<<" "<<x;
				return 0;
			}
		}
		if(y%2==0) for (int x=n;x>=1;x--)
		{
			cnt++;
			if(a[cnt]==num)
			{
				cout<<y<<" "<<x;
				return 0;
			}
		}
	}
	return 0;
}

