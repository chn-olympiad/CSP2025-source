#include<bits/stdc++.h>
using namespace std;
int a[105];
bool ma(int x,int y)
{
	return x>y;
}
int main()
{
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,p,px=1,py=1,pi=0;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
	{
		cin>>a[i];
		if(i==1)p=a[i];
	}
	sort(a+1,a+n*m+1,ma);
	for(int i=1;i<=n*m;i++)if(a[i]==p)pi=i;
	py=pi/n;
	if(pi%n!=0)py+=1;
	px=(pi-1)%m+1;
	if(py%2==1)cout<<py<<" "<<px;
	else cout<<py<<" "<<m-px+1; 
}
