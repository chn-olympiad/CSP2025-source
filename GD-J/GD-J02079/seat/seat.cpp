#include<bits/stdc++.h>
using namespace std;
int a[15],b[15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=n*m;
	int c=0,r=0;//ÁÐ ÐÐ  
	for(int i=1;i<=sum;i++){
		cin>>a[i];
	}
	int a1=a[1];
	int x=0; 
	sort(a+1,a+sum+1);
	
	for(int i=sum;i>=1;i--){
			b[i]=a[i];
			if(b[i]==a1){
				x=sum-i+1;
			}
		}
	c=(x+(n-1))/n;
	cout<<c<<" ";
	
	if(c%2==0){
		if(x%n==0){
		cout<<1;
	}
		else{
			cout<<(n+1)-(x%n); 
	}
}
	else{
		if(x%n==0){
			cout<<n;
		}
		else{
			cout<<x%n;
		}
	}
	
	return 0;
}
