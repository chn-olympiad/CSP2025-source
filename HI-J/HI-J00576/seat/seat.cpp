#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y;
	cin>>x>>y;
	int sa[x*y]={};
	for(int i = 0;i<x*y;i++){
		cin>>sa[i];
	}
	int w=sa[0];
	for(int i = 0;i<=x*y;i++){
		for(int j = 0;j<=i;j++){
			if(sa[i]>sa[j]){
				swap(sa[i],sa[j]);
			}
		}
	}
	int d;
	for(int i = 0;i<x*y;i++){
		if(sa[i]==w){
			d=i;
			d++;
		}
	}
	int az=d/x+1;
	int af=d%y;
	if(af==0){
		af=y;
	}
	
	cout<<az<<" "<<af;


	
	return 0;
}




