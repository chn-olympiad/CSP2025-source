#include<bits/stdc++.h>
using namespace std;
int n,m;
int num_;
int a[105],b[105];
void dfs(int x_,int y_,int i,bool flag){
	if(b[i]==num_){
		cout<<y_<<" "<<x_;
		return;
	}
	if(x_+1>n&&flag){
		dfs(x_,y_+1,i+1,false);
	}else if(x_-1<=0&&flag==false){
		dfs(x_,y_+1,i+1,true);
	}else{
		if(flag){
			dfs(x_+1,y_,i+1,flag);
		}else{
			dfs(x_-1,y_,i+1,flag);
		}
	}
	return;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}	
	num_=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		b[i]=a[n*m-i+1];
	}
	dfs(1,1,1,true);
	return 0;
}
/*
10 10
5 5 7 7 7 7 7 9 9 9 9 9 9 9 9 9 9 9 9 9 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 8 6 6 6 6 6 6 6 6 6 6 
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
*/ 
