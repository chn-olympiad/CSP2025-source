#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int m,n,a[1001];
int x,y;
bool cmp(int c,int d){ 
	return c>d; 
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;//n行m列
	for(int i=1;i<=n*m;i++){//m*n=100
		cin>>a[i];
	} 
	int b=a[1];
	sort(a+1,a+n*m+1,cmp);
	int ans=1;
	for(int i=1;i<=n*m;i++){
		if(b==a[i]){
			break;
		}
		ans++; 
	} //无误
	if(ans%n==0){
		y=ans/n;
		if(y%2==0){
			x=1;
		}else{
			x=n;
		}
	}else{
		y=ans/n+1;
		if(y%2==0){
			x=n+1-(ans%n);
		}else{
			x=ans%n;
		}
	}
	cout<<y<<" "<<x;
	
	return 0;
} 
/*
1=拿下！

注意freopen注释 
2.100
 
*/