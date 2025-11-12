#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	cin>>a>>b;
	int sum=a*b;
	int m[100];
	for(int i=0;i<sum;i++){
		cin>>m[i];
	}
	int c=m[0];
	for(int i=0;i<sum;i++){
	if(m[i]<m[i+1]){
		int a;
		a=m[i];
		m[i]=m[i+1];
		m[i+1]=a;
	}
	for(int j=0;j<sum;j++){
		if(m[j]<m[j+1]){
			int a;
			a=m[j];
			m[j]=m[j+1];
			m[j+1]=a;
		}
	}	
}int d;
	for(int i=0;i<sum;i++){
		if(c==m[i])
		i++;
		b=i/a+1;
		d=abs(i-b*a);
	}
	cout<<d<<' '<<b;
	return 0;
}
	
