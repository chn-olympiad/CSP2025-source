#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005];
int f[105][105];
bool cmp(int x,int y)
{
	return x>y;
}
signed main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	int flag=a[1];
	sort(a+1,a+n*m+1,cmp);
	int p;
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==flag)
		{
			p=i;
			break;
		}
	}
	int f=1+(p/(2*n))*2,s=(p%(2*n));
	if(s>n)
	{
		f++;
		s-=n;
		s=n-s+1;
	}
	cout<<f<<" "<<s;
}
