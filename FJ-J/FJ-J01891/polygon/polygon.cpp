#include<iostream>
using namespace std;
int n,a[5005],m=3,big=0,s=0,count=0;
int main(){
	// ÊäÈë 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	while(m<=n){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) if(a[j]>big) big=a[j];
			for(int j=0;j<m;j++) s+=a[j];
			if(s>2*big){
				count++;
			}
		}
		m++;
	}
	cout<<count;
	return 0;
}
