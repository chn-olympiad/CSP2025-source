#include <bits/stdc++.h>
using namespace std;
int b[101];
int main(){
	ifstream in("seat.in");
	ofstream out("seat.out");
	int n,m,r,num,C,R;
	in>>n>>m;
	for(int i=1;i<=n*m;i++){
	    in>>b[i];
	} 
	r=b[1];
	for(int i=1;i<n*m;i++){
		for(int j=i+1;j<=n*m;j++){
			if(b[i]<b[j]) swap(b[i],b[j]);
		}
	}
	 int f=0;  
	for(int i=1;i<=n*m&&f==0;i++){
		if(b[i]==r){
		    num=i;
		    f=1;
		} 
	}
	int yu;
	yu=num%n;
	if(yu==0){
		C=num/n;
		if(C%2==0){
		    R=1;	
		}
		else{
			R=n;
		}
	}
	else{
		C=num/n+1;
		if(C%2==0){
		    R=n-yu+1;	
		}
		else R=yu;
	}
	out<<C<<" "<<R;

	in.close();
	out.close();
}
