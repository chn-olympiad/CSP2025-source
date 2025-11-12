#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],b[105],ax=-2,x=1,u,c,r,d;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
    for(int i=1;i<=n*m;i++)
    {
		ax=-2;
		for(int j=1;j<=n*m;j++)
		{
			if(a[j]>=ax&&b[j]==0)
			{
				ax=a[j];
				u=j;	
			}
		}
		b[u]=x;
		x+=1;
	}
	/*
	for(int i=1;i<=n*m;i++) cout<<b[i]<<" ";
	cout<<endl;
	*/
	c=(b[1]+n-1)/n;
	d=b[1]%(2*n);
	if(d==0) d=2*n;
	if(d<=n) r=d;
	else r=2*n+1-d;
	cout<<c<<" "<<r;
    return 0;
}
