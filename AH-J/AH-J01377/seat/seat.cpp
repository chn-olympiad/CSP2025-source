#include <bits/stdc++.h>
using namespace std;
int n,m;
int b[110];
int a[12][12];
bool cmp(int c,int d)
{
	return c>d;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	bool p=1;
	int sum=n*m;
	for(int i=1;i<=sum;i++)
		cin>>b[i];
	int x=b[1],wz;
	sort(b+1,b+1+sum,cmp);
	for(int i=1;i<=sum;i++)
		if(b[i]==x)
		{
			wz=i;
			break;
		}
	if(wz%n==0) p=0;
	int j=wz/n+p;
	int i;
	if(j%2==0)
	{
		i=j*n-wz+1;
	}
	else i=wz-j*n+n;
	cout<<j<<' '<<i;
	return 0;
}
