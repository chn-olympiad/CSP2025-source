#include <bits/stdc++.h>
using namespace std;
struct node{
	int mark,num;
}a[110];
int n,m,anum,ax,ay;
bool cmp(node x,node y){
	return x.mark>y.mark;	
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].mark;
		if(i==1) a[i].num=1;
		else a[i].num=0;
	} 
	sort(a+1,a+m*n+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].num==1){
			anum=i;
			break;
		}  
	}
	if(anum%n==0){
		ax=anum/n;
		if(ax%2==1) ay=n;
		else ay=1;
	}
	else{
		ax=anum/n+1;
		if(ax%2==1)	ay=anum%n;
		else ay=n-anum%n+1;
	}
	cout<<ax<<" "<<ay;
	return 0;
}
