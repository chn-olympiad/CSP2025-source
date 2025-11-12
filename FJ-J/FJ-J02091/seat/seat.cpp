#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,id,x,y,s;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			s=a[i];
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			id=i;
		}
	}
//	cout<<id<<"\n";
	if(id&n==0){
		x=id/n;
	}
	else if(id%n!=0){
		x=id/n+1;
	}
	if(x%2==1){
		y=id-(x-1)*n;
	}
	else if(x%2==0){
		y=abs(n*x-id)+1;
	}
	cout<<x<<" "<<y;
	return 0;
}
