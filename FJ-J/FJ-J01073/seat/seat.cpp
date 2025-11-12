#include <bits/stdc++.h>
using namespace std;
int a[100+10];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,o,p,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
	 } 
	 x=a[1];
	 sort(a+1,a+m*n+1);
	 reverse(a+1,a+m*n+1);
	 for(int i=1;i<=m*n;i++)
	 {
	 	if(a[i]==x)
	 	{
	 		y=i;
	 		break;
		 }
	 }
	 if(y%m==0)
	 {
	 	p=y/m;
	 	if(p%2==1)
	 {
	 	o=m;
	 }
	 else
	 {
	 	o=1;
	 }
	 }
	 else
	 {
	 	p=y/m+1;
	 	if(p%2==1)
	 {
	 	o=y%m;
	 }
	 else
	 {
	 	o=m-y%m+1;
	 }
	 }
	 cout<<p<<" "<<o<<endl;
	return 0;
}
