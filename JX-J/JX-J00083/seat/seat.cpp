#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,num,ax,ay;
struct node{
	int x,pos;
}a[105];
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
	}
	a[1].pos=1;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].pos==1){
			num=i;
		}
	}
	if(num%n==0){
		ax=num/n;
	}
	else{
		ax=num/n+1;
	}
	if(ax%2==0){
		if(num%n==0){
			ay=1;
		}
		else{
			ay=n-(num%n)+1;
		}
	}
	else{
		if(num%n==0){
			ay=n;
		}
		else{
			ay=(num%n);
		}
	}
	cout<<ax<<" "<<ay;
		
	return 0;
}
