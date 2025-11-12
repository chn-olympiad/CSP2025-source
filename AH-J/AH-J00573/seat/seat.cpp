#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],x,r,pr;
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	freopen("seat.in" ,"r",stdin );
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	scanf("%d",&a[i]);
	r=a[1];
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++)
	if(a[i]==r)  pr=i;
	int lie=(pr-1)/n+1,hang=(pr-1)%n+1;
	if(lie%2==0)
	hang=n-hang+1;
	cout<<lie<<" "<<hang;
}
