#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,df,mc,x,y;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int d=n*m;
	for(int i=1;i<=d;i++){
		cin>>a[i];
	}
	df=a[1];
	sort(a+1,a+d+1,cmp);
	for(int i=1;i<=d;i++){
		if(a[i]==df){
			mc=i;
			break;
		}
	}
	if(mc%n==0){
		x=mc/n;
		if(x%2!=0) y=n;
		else y=1;
	}
	else{
		x=mc/n+1;
		if(x%2!=0) y=mc%n;
		else y=n-mc%n+1;
	}
	cout<<x<<" "<<y<<endl; 
	
	
	
	
	
	
	
	return 0;
}
