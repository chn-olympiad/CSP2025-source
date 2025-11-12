#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m;
	int ans=1;
	scanf("%d %d",&n,&m);
	long long num;
	num=n*m;
	int a1=0;
	int a2=0;
	for(int i=0;i<num;i++){
		if(i==0)scanf("%d",&a1);
		if(i!=0)scanf("%d",&a2);
		if(a1<a2){
			ans++;
		}
	}
	int x=0,y=0;
	y=ans/n+(ans%n!=0);
	if(y%2!=0){
		x=n-ans%n;
	}
	if(y%2==0){
		x=ans%n-n;
	}
	printf("%d",y);
	printf("%d",x);
	return 0;
}
