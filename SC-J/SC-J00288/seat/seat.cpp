#include<bits/stdc++.h>
using namespace std;
int a[2020],h,l;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,cnt;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		scanf("%d",&a[i]);
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++)
	{
		if(j%2==1)
		for(int i=1;i<=n;i++)
			if(a[(j-1)*n+i]==cnt)
			{
				cout<<j<<" "<<i;
				return 0;
			}	
		if(j%2==0)
		for(int i=n;i>=1;i--)
			if(a[(j-1)*n+(n-i+1)]==cnt)
			{
				cout<<j<<" "<<i;
				return 0;
			}
	}
}