#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,sum;
	int my,set(0);
	int j(1);
	int c,r;
	int a[110];
	int a1[110];
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>a1[i];
	}
	my=a1[1];
	sort(a1+1,a1+sum+1); 
	for(int i=sum;i>=1;i--){
		a[j]=a1[i];
		j++;
	}
	for(int i=1;i<=sum;i++){
		if(my==a[i]){
			set=i;
			break;
		}
	}
	c=(set+n-1)/n;
	if(c%2==1){
		r=1+(set+n-1)%n;
	}else{
		r=n-(set+n-1)%n;
	}
	cout<<c<<" "<<r;
	
	return 0;
}
