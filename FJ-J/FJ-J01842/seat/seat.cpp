#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("seat.in");
	ofstream fout("seat.out");
	int m,n;
	int flag=0;
	fin>>n>>m;
//	cin>>n>>m;
	int a[m*n];
	int b[n][m];
	for(int i=0;i<m*n;i++){
		fin>>a[i];
//		cin>>a[i];
	}
	int rgrade=a[0];
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n;j++){
			if(a[i]>a[j]){
				int t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=0;i<m*n;i++){
		if(a[i]==rgrade){
			flag=i+1;
		}
	}
	int x,y;
	if(flag%(2*n)<=n&&flag%n!=0){
		if(flag/n*n<flag){
			x=flag/n+1;
			y=flag%n;
		}else{
			x=flag/n;
			y=flag%n;
		}
	}else{
		if(flag/n*n<flag){
			x=flag/n+1;y=n-flag%n;
		}else{
			x=flag/n;y=n-flag%n;
		}
	}
	fout<<x<<" "<<y;
//	cout<<x<<" "<<y;
	fin.close();
	fout.close();
	return 0;
}
