#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[10000];
int b[30][30];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	}
	int sum=a[1];
	sort(a+1,a+1+(n*m),greater<int>());
	int ans=1;
	int x=1,y=0;
	bool fangxiang=1;
	int i=1;
	while(ans<=n*m)
	{
		if(fangxiang==1) y++;
		if(fangxiang==0) y--;
		if(y==m+1) 
		{
			y--;
			x++;
			fangxiang=0;
		}
		if(y==0)
		{
			y++;
			x++;
			fangxiang=1;
		}
		b[y][x]=a[i];
		if(b[y][x]==sum)
		{
			cout<<x<<" "<<y;
			return 0;
		}
		i++;
		ans++;
	}
	
	return 0;
}

