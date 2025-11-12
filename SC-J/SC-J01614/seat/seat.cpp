#include<bits/stdc++.h>
using namespace std;
int n,m,sum,x,y;
int a[205];
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int u=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==u){
			sum=i;
			break;
		}
	}
	if(sum%n==0){
		y=sum/n;
		if(y%2==0) x=1;
		else x=n;
	}
	else{
		y=sum/n+1;
		if(y%2==0) x=n-sum%n+1;
		else x=sum%n;
	}
	cout<<y<<" "<<x;
	return 0;
}