#include<bits/stdc++.h>
using namespace std;
long long n,m,a[33333],f[3333][3333];
void fre()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
}
int main()
{
	fre();
	cin>>n>>m;
	long long l=n*m;
	for(long long i=1;i<=l;i++) cin>>a[i];
	long long now=a[1],Pos=1;
	sort(a+1,a+1+l),reverse(a+1,a+1+l);
	for(long long i=1;i<=n;i+=2)
	{
		for(long long j=1;j<=m;j++) f[i][j]=a[Pos],Pos++;
		for(long long j=m;j>=1;j--) f[i+1][j]=a[Pos],Pos++;
	}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=m;j++)
			if(now==f[i][j])
				cout<<i<<" "<<j,exit(0);
	return 0;
}
