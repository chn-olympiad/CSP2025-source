#include<iostream>
using namespace std;
int n,x=0,a[10000];
void solve(int m,int p,int q){
	if(m==1){
		for(int i=p;i<n-m;i++){
			if(q>a[i]){
				x++;
			}
		}
	}
	for(int i=p;i<=n-m;i++){
		solve(m-1,p-1,a[i]+q);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		for(int j=i;j>0;j--){
			if(a[j]<a[j-1]){
				int m=a[j];
				a[j]=a[j-1];
				a[j-1]=m;
			}
		}
	}
	for(int i=3;i<=n;i++){
		solve(i,0,0);
	}
	cout<<x;
	return 0;
}
