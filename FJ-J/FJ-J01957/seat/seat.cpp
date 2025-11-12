#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c=a*b;
	if(a==1&&b==1){
		cout<<1<<1;;
	}
	if(a==1&&b==2){
		int d,e;
		cin>>d>>e;
		if(d>e){
			cout<<1<<" "<<1;
		}
		else{
			cout<<1<<" "<<2;
		}
	}
	if(a==2&&b==1){
		int d,e;
		cin>>d>>e;
		if(d>e){
			cout<<1<<" "<<1;
		}
		else{
			cout<<2<<" "<<1;
		}
	}
	if(a=2&&b==2){
		int d,e,f,g;
		cin>>d>>e>>f>>g;
		if(d>e&&d>f&&d>g){
			cout<<1<<" "<<1;
		}
		if(d<e&&d>f&&d>g||d<f&&d>e&&d>g||d<g&&d>f&&d>e){
			cout<<1<<" "<<2;
		}
		if(d<e&&d>f&&d>g||d<f&&d>e&&d>g||d<g&&d>f&&d>e){
			cout<<1<<" "<<2;
		}
		if(d<e&&d<f&&d>g||d<e&&d<g&&d>f||d<f&&d<g&&d>e||d<f&&d<e&&d>g||d<g&&d<f&&d>e||d<g&&d<e&&d>f){
			cout<<2<<" "<<2;
		}
		else{
			cout<<2<<" "<<1;
		}
	}
	return 0;
}
