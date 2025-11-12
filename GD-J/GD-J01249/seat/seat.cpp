#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
long long n,m,bj,a[1006],s,ans;
string st;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++) 
	{
		if(a[i]==s)
		{
			bj=i;	
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(i%2==0)
		{
			for(int j=n;j>=1;j--)
			{
				ans++;
				if(ans==bj) cout<<i<<' '<<j;
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				ans++;
				if(ans==bj) cout<<i<<' '<<j;
			}
		}
	}
	return 0;
}
