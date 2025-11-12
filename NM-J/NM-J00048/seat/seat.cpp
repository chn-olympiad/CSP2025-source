#include<bits/stdc++.h>
using namespace std;
char a[102];
int c[1000];
int n,m;
int r,j,k;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);
cin>>n>>m;
for(int i=0;i<=m*n;i++)
{
	cin>>a[i];
}
j=a[0];
sort(a,a+n*m,cmp);
for(int k=0;k<=n*m;k++)
{
if(j==a[k])
{
	cout<<n<<" "<<k-1;
}
 } 


	return 0;
}
