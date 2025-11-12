#include<bits/stdc++.h>
using namespace std;
ifstream fin("seat.in");
ofstream fout("seat.out");
int main(){
	int n,m,step,r=0;bool ok=1;
	int a[200];
	fin>>n>>m;
	for(int i=0;i<n*m;i++){
		fin>>a[i];
	}
	for(int i=0;i<n*m-1;i++){
		step=0;
		ok=1;
		for(int j=0;j<n*m;j++){
			if(a[j]<a[j+1]){
				step=a[j];
				a[j]=a[j+1];
				a[j+1]=step;
				ok=0;
				if(j==r){
					r+=1;
				}
			}
		}
		if(ok==1){
			break;
		}
	}
	r++;
	int c;
	if(r%n!=0){
		c=(r/n)+1;
		fout<<c<<' ';
	}else{
		c=(r/n);
		fout<<c<<' ';
	}
	if(c%2==0){
		fout<<n-r%n+1;
	}else{
		fout<<r-(c-1)*n;
	}
	return 0;
}
