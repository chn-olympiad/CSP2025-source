#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int a,int b){
	return a>b;
}
int f(int x,int y){
	double a=x/y;
	if(x%y==0){
		return x/y;
	}
	if(y%x==0){
		return y/x;
	}
	return (int)a+1;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k=a[0],p=0;
	sort(a+0,a+n*m,cmp);
	for(int i=0;i<n*m;i++){
		if(a[i]==k){
			p=i+1;
			break;
		}
	}
	int x=f(p,n);//1.5   2
	int t=p%(n),y=0;//0
	if(x%2==1){
		if(t==0){
			y=n;
		}
		else{
			y=t;
		}
	}
	else{
		if(t==0){
			y=1;
		}
		else{
			y=n-t+1;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}

