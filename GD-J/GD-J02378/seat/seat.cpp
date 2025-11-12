#include<bits/stdc++.h>
using namespace std;
long long a[1000],n,m,x,r,l=1,h=1;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	a[r]=1;
	for(int i=2;i<=n*m;i++)
	cin>>x,a[x]=1;
	for(int i=100;i>=1;i--)
	{
		if(a[i]==0)continue;
		if(i==r)
		{
			cout<<l<<" "<<h;
			return 0;
		}
		if(l%2==1)h++;
		else h--;
		if(h==0||h==n+1)
		{
			l++;
			if(h==0)h=1;
			else h=n;
		}
	}
	return 0;
}
