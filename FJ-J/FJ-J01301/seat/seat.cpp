#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int k=a[1],kk;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==k){
			kk=i;
		} 
	}
	int x,y;
	if(kk%n==0){
		y=kk/n;
	}else{
		y=kk/n+1;
	}
	if(y%2==0){
		x=n-(kk%n)+1;
	}else{
		if(kk%n==0){
			x=n;
		}else{
			x=kk%n;
		}
	}
	cout<<y<<' '<<x;
	return 0;
}
