#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,a[105],num,num1,count=0;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	num=a[0];
    for(int i=1;i<n*m;i++){
		if(a[i]>a[i-1])	{
			swap(a[i],a[i-1]);
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==num){
			num1=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				count++;
				if(count==num1){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				count++;
				if(count==num1){
					cout<<i<<" "<<j;
					break;
				}
			}
		}
		
	}			
	
	
	

}
