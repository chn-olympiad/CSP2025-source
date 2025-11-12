#include<iostream>
using namespace std;
int main(){
	int t,k=0,u=0,e=0;
	cin>>t;
	for(int q=1;q++;q<=t){
	int n,a[1000][1000],r;
	cin>>n;
	for(q=1;q++;q<=n){
		cin>>a[q][1]>>a[q][2]>>a[q][3];
	}
	for(q=1;q++;q<=n){
		if(a[q][1]>a[q][2]>a[q][3]){

			k++;
		}
		if(a[q][1]>a[q][3]>a[q][2]){
			k++;
		}
		if(a[q][2]>a[q][3]>a[q][1]){
			u++;
		}
		if(a[q][2]>a[q][1]>a[q][3]){
			u++;

		}
		if(a[q][3]>a[q][1]>a[q][2]){
			e++;
		}
		if(a[q][3]>a[q][2]>a[q][3]){
			e++;
		}
	}
	if(2e>n||2u>n||2k>n){



	}


















	}




}
