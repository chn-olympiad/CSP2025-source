#include<iostream>
using namespace std;
int main(){
	long long int max=0,n,r,s;
	long long int sum[100000]={};
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r;
		for(int j=0;j<r;j++){
			for(int f=0;f<3;f++){
				cin>>s;
				if(s>max){
					max=s;
				}
			}
			sum[i]=max+sum[i];
			max=0;
			
		}
	
	}
	for(int i=0;i<n;i++){
		cout<<sum[i]<<"\n";
	}
	
	return 0£» 
}
