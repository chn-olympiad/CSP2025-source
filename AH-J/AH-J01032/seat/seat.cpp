#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,d,g;
	cin>>n>>m;
	int a[n*m];
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	int e=a[0];
	for(int i=0;i<n*m-1;i++){
		for(int x=0;x<n*m-1;x++){
			if(a[x]<a[x+1]){
				d=a[x];
				a[x]=a[x+1];
				a[x+1]=d;
			}
		}
	}
	for(int i=0;i<n*m;i++){
		if(a[i]==e){
			g=i;
			break;
		}
	}
	int p=(g/n)+1;
	if(p%2==1){
		cout<<p<<" "<<g%n+1;
	}
	else{
		cout<<p<<" "<<n-(g%n);
	}
	return 0;
}
