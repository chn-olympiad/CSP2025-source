#include<bits/stdc++.h>
using namespace std;
int c,r,sum=0,n,m;
int a[110];
int main(){
	freopen("seat.in","r",std.in);
	freopen("seat.out","w",std.out);	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int flag=a[1];
	sort(a+1,a+n*m+1);
	
	
	
	for(int i=n*m;i>=1;i--){
		if(flag==a[i]){
			sum=n*m-i+1;
		}
	}
	
	
	
	if(sum%n==0){
		c=sum/n;
		if(c%2==1){
			r=n;
		}
		else{
			r=1;
		}
	}
	else{
		c=sum/n+1;
		if(c%2==1){
			r=sum%n;
		}
		else{
			r=n-sum%n+1;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
