#include<bits/stdc++.h>
using namespace std;
int n,m,w,z,x,a=1,b=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<n*m;i++){
		cin>>w;
		if(w>x) z++;
	}
	while(z!=0){
		if(z==0) cout<<b<<" "<<a,exit(0);
		a=1;
		for(int i=1;i<n;i++){
			z--;
			a++;
			if(z==0) cout<<b<<" "<<a,exit(0);
		}
		b++;
		z--;
		a=n;
		if(z==0) cout<<b<<" "<<a,exit(0);
		for(int i=n;i>1;i--){
			z--;
			a--;
			if(z==0) cout<<b<<" "<<a,exit(0);
		}
		b++;
		z--;
		a=1;
		if(z==0) cout<<b<<" "<<a,exit(0);
	}
} 
