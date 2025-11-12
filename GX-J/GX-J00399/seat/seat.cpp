#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,c,r,max=-1,x,i2,j;
	cin>>n>>m;
	int a[n*m+1],b[n*m+1];
	for(int i=1;i<=n*m+1;i++){
		cin>>a[i];
	}
	
	x=a[1];
	for(int i=1;i<=n*m+1;i++){//pai xu
		max=-1;
		if(a[i]>max){
			max=a[i];
			i2=i;
		}
		b[i]=max;
		a[i2]=-1;
	}
	for(j=1;j<=n*m+1;j++){//qiu pai ming
		if(b[j]==x)
		break;
	}
	
	c=(j+3)/n;
	if(c%2==1){
		if(j%4==0)r=4;
		else r=j%4;
	}
	if(c%2==0){
		if(j%4==0)r=1;
		if(j%4==1)r=4;
		if(j%4==2)r=3;
		if(j%4==3)r=2;
	}
	cout<<c<<" "<<r;
	return 0;
}
