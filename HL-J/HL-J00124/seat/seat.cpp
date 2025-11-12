#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N];
int d[N][N];
int n,m,x,y;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1) x=a[i];
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
	{
		if(a[i]==x) y=n*m-i;
	}
	if((y/m)%2==0) cout<<y/m+1<<" "<<0+y%m+1<<endl;
	if((y/m)%2==1) cout<<y/m+1<<" "<<m-y%m<<endl;
}
