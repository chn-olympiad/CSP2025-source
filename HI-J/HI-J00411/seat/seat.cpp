#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,xm;
int a[110];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	xm=a[0];
	sort(a,a+n*m);
	for(int i=0;i<n*m/2;i++)swap(a[i],a[n*m-i-1]);
	//for(int i=0;i<n*m;i++)cout<<a[i]<<' ';
	
	for(int i=0;i<n*m;i++){
		if(a[i]==xm){
			c=i/m+1;
			if(c%2==1)r=i%m+1;
			else r=n-i%m;
			break;
		}
	}
	printf("%d %d",c,r);
	return 0;
}
