#include <bits/stdc++.h>
using namespace std;
int n,m,c,r,x=0,y=1;
int a[105],b[105];
int main()
{
	freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>m>>n;
    for(int i=0;i<m*n;i++){
		cin>>a[i];
	}
	int xm=a[0];
	sort(a,a+m*n);
	for(int i=n*m-1;i>-1;i--)
	{
		b[y]=a[i];
		cout<<b[y]<<" ";
		y++;
	}
	while(1<2){
		x++;
		if(b[x]==xm){
			break;
		}	
	}
	//cout<<x<<endl;
	c=x/n;
	if(x%n!=0){
		c++;}
	if(c%2==1){
		r=x%n;
		if(r==0){
			r=n;
		}
	}
	else if(c%2==0){
		r=m-(x%n+1);
		if(r==0){
			r=n;}
	}
	cout<<c<<" "<<r;
	return 0;
}
