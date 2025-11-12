include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n,a[m*n],k,e;
	cin>>m>>n;
	for(int i=0;i<=m*n;i++){
		cin>>a[i];
	}
	g=a[0];
	for(int j=0;j<=m*n;j++){
		if(a[j]<a[j+1]){
			k=a[j];
			a[j]=a[j+1];
			a[j+1]=k;
		}
	}
	for(int r=0;r<=100;r++0{
		whlie(g=a[r]){
			e=r;
		}
	}
	cout<<e;
}


