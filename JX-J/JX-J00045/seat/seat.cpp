#include<bits/stdc++.h>
using namespace std;
int a[10010],n,m,o=1,x,y,h,l;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	x=a[0];
	sort(a,a+n*m);
	for(int i=n*m-1;i>=0;i--,o++)
	if(a[i]==x){
	y=o;
	break;}
	for(int i=0;i<m;i++)
	if(y>=i*n+1&&y<=n*(i+1)){
	l=i+1;
	break;}
	y-=(l-1)*n;
	if(l%2==1)h=y;
	if(l%2==0)h=n+1-y;
	cout<<l<<" "<<h;
}
