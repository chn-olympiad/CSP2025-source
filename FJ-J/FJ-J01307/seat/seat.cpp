#include<iostream>
using namespace std;
int m,n,a[10001],p=0,c,r,x,y;//n行m列 c列r行 
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	x=m*n;
	for(int i=1;i<=x;i++) cin>>a[i];
	y=a[1];//午夜降临 噩梦开启 
	for(int i=1;i<=x;i++){
		for(int j=i+1;j<=x;j++){
			if(a[i]<a[j]){
				p=a[i];
				a[i]=a[j];
				a[j]=p;
			}
		}
	}//这是我的决斗 
	for(int i=1;i<=x;i++){
		if(a[i]==y){
			if(i%n==0) c=n/i;
			else c=(i/n)+1;
		}
	}//饿啊来吧走起 
	for(int i=1;i<=x;i++){
		if(a[i]==y){
		 	if(2*m>i) r=i/m+1;
		 	else r=m/i+1;
		}
	}
	cout<<c<<" "<<r;
	return 0;
}

