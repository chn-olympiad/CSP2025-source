#include<cstdio>
#include<iostream>
#include<stdio.h> 
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[99999],t,c,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int e=a[1];
	for(int i=1;i<=n*m-1;i++){
		for(int j=1;j<=n*m-i;j++){
			if(a[j]<a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==e){
			c=(i+(n-1))/n;
			cout<<c<<" ";
			r=i-(c-1)*n;
			cout<<r;
		}
	}
	return 0;
}
