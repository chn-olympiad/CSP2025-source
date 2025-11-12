#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int a[100005];
bool pd(int x,int y){
	return x>y;
}                                                   
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);  
	
	cin>>n>>m;
	for(int i = 1;i<=n*m;i++){
		cin>>a[i];
	}
	int len = n*m;//数组长度 
	int sum = a[1];//小R成绩 
	int x_y;
	sort(a+1,a+len+1,pd);
	
	for(int i = 1;i<=len;i++){
		if(a[i]==sum){
			x_y = i;
		}
	} 
	
	if(x_y%n == 0){
		c = x_y/n;
	}else if(x_y<n){
		c = 1;
	}else{
		c = x_y/n+1;
	}
	
	
	if(x_y<n){
		r = x_y;
	}else if(x_y == n){
		r = x_y;
	}else if(x_y%n==0&&c%2!=0){
		r = n;
	}else if(x_y%n==0&&c%2==0){
		r = 1;
	}else if(x_y%n!=0&&c%2!=0){
		r = x_y%n;
	}else if(x_y%n!=0&&c%2==0){
		r = (n+1)-x_y%n;
	}
	
	cout<<c<<" "<<r;
	return 0;
}
