#include<iostream>
using namespace std;
int main(){
	int m,count=0;
	cin>>m;
	int a[m];
	for(int i=0;i<m;i++){
		cin>>a[i];
	}
	for(int k=3;k<=m;k++){
		for(int a1=0;a1<=m-k+1;a1++){
			for(int a2=a1+1;a2<=m-k+2;a2++){
			    for(int a3=a2+1;a3<=m;a3++){
			        if(a[a1]+a[a2]+a[a3]>2*max(a[a1],a[a2],a[a3])){
			        	count++;
					}
		        }
		    }
		}
	}
	cout<<count%998;
return 0;
}
