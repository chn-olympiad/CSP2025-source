#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long m,n,a[11][11]={},v[11][11]={},b[101]={};
	cin>>m>>n;
	long long k=m*n;
   for(int i=1;i<=k;i++)
{
	cin>>b[i];
}
long long g=b[1];
long long m1=1,n1=1;
sort(b+1,b+k+1);
while(k>0)
{
	a[n1][m1]=b[k];
	v[n1][m1]=1;
	if(v[n1+1][m1]==0&&n1+1<=m)
	n1++;
	else if(v[n1-1][m1]==0&&n1-1<=1)
	n1--;
	else if(m1+1<=n)
	m1++;
	k--;
}
for(int c=1;c<=n;c++)
{
	for(int r=1;r<=m;r++)
	{
		if (a[c][r]==g)
		cout<<r<<" "<<c;
	}
}
return 0;
}
