#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[110]={};
	cin>>n>>m;
	int sum=0,num=0;
	for(int i=1;i<=m*n;i++){
		cin>>a[i];
	}
	sum=a[1];
	sort(a,a+m*n+1);
	for(int i=n*m;i>0;i--){
		if(a[i]==sum){
			num=n*m+1-i;
		}
	}
	int bum=num/n;
	if(num<=n && num>=1){
		cout<<1<<" "<<num;
	}else if (num>n && num<=m*n && bum%2==0){
		if(num%n==0){
			cout<<bum<<" "<<1;	
		}else{
			cout<<bum+1<<" "<<num%n;
		}
		
	}else if(num>n && num<=m*n && bum%2==1){
		if(num%n==0){
			cout<<bum<<" "<<4;
		}else{
			cout<<bum+1<<" "<<n+1-num%n;
		}
	}
	return 0;
}

