#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
int n,m,sum,c,r;
int a[1005],num,pos;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a[i];
		if(i==1) num=a[i];
	}
	sort(a+1,a+sum+1,cmp);
	for(int i=1;i<=sum;i++){
		if(a[i]==num) pos=i;
	}
	if(pos%n==0) c=pos/n;
	else c=(pos/n)+1;
	if(c%2==1){
		if(pos%n==0) r=n;
		else r=pos%n;
	}
	else{
		if(pos%n==0) r=1;
		else r=(n+1)-(pos%n);
	}
	cout<<c<<" "<<r;
	return 0;
}
