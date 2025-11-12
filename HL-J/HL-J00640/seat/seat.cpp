#include <bits/stdc++.h>
using namespace std;
int n,m,a[120],z,mark,r,x,y,t,w;
int seat(){
	
}
int main(){
	int q;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++){
		cin>>a[i];
	}
	mark=a[1];
	for(int i=1;i<=z;i++){
		for(int j=1;j<=z;j++){
			if(a[i]>a[j]){
			q=a[i];
			a[i]=a[j];
			a[j]=q;	
			}
		}
	}
	for(int i=1;i<=z;i++){
		if(a[i]==mark) r=i;
	}
	if(n==1) t=r%1;w=r/1;
	if(n==2) t=r%2;w=r/2;
	if(n==3) t=r%3;w=r/3;
//	if(n==4) t=r%4;w=r/4;
	//if(n==5) t=r%5;w=r/5;
//	if(n==6) t=r%6;w=r/6;
//	if(n==7) t=r%7;w=r/7;
//	if(n==8) t=r%8;w=r/8;
//	if(n==9) t=r%9;w=r/9;
//	if(n==10) t=r%10;w=r/10;
//	seat();
	if(t==0) y=w;
	else y=w+1;
	
	if(y%2==0){
		if(t==0) x=1;
		else x=n-t+1;
	}
	
	if(y%2==1){
		if(t==0) x=n;
		else x=t;
	}
	cout<<y<<' '<<x;
	return 0;
}
