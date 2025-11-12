#include<iostream>
using namespace std;
int main(){
	int n,m,s,x=0;
	cin>>n>>m;
	int a[n*m],b[n][m];
	cin>>a[0];
	s=a[0];
	for(int i=1;i<n*m;i++){
		cin>>a[i];
		for(int j=i;j>0;j--){
			if(a[j]>a[j-1]){
				int m=a[j];
				a[j]=a[j-1];
				a[j-1]=m;
			}
		}
	}
	for(int i=0;i<m;i++){
		if(i%2==0){
			for(int j=0;j<n;j++){
				if(a[x]==s){
					cout<<i+1<<" "<<j+1; 
				}
				x++;
			}
		}else{
			for(int j=n-1;j>=0;j--){
				if(a[x]==s){
					cout<<i+1<<" "<<j+1; 
				}
				x++;
			}
		}
	}
	return 0;
}
