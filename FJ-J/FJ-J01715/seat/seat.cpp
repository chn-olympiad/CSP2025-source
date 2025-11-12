#include<iostream>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,m;
	cin>>n>>m;
	int a[n*m];
	int x=m*n;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int k=a[0];
	int N=1,M=1;
	sort(a,a+x,cmp);
	for(int i=0;i<x;i++){
		if(a[i]==k){
			cout<<M<<" "<<N;
		}
		if(M%2){
			if(N+1>n){
				M++;
			}else{
				N++;
			}
		}else{
			if(N-1<1){
				M++;
			}else{
				N--;
			}
		}	
	}
	return 0;
}
