#include<bits/stdc++.h> 
using namespace std;
int zw[12][12],m,n,i,j,k,x,y; 
struct xx{
	int cj;
	bool xt=0;
};
bool cmp (xx pp,xx oo){
	return pp.cj<oo.cj;
}
int main ()
{
	
freopen(" seat.in","r",stdin);
freopen("seat.out","w",stdout);
	xx csp[105];
	csp[1].xt=1;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			cin>>csp[i*m-m+j].cj;
		}
	}
	sort(csp+1,csp+n*m+1,cmp);
	
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(csp[i*m-m+j].xt) k=n*m-(i*m-m+j)+1;
		}
	}
	x=k/n+1;
	y=k%n;
	if(y==0){
		y=n;
		x--;
	} 
	if(x%2==0) y=n-y+1;
	cout<<x<<" "<<y;
	return 0;
}
