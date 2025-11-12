#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],c,sum,x,y;
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
	c=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==c) sum=i;
	}
	if(sum%m==0){
		y=(sum/m);
		x=n;
	} 
	else{
		y=(sum/m)+1;
		if(y%2==1) x=sum%m;
		else x=sum%m+1;
	}
	cout<<y<<" "<<x; 
	return 0;
}
