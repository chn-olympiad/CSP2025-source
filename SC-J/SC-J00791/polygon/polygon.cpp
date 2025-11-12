#include<bits/stdc++.h> 
using namespace std;
long long a=0,b,zd=0,zsq=0;
long long c[10000];
int as(int z,int y){
	for(int i=z;i<=b-y+1;i++){
		if(z==1){
			a=c[i];
			zd=c[i];
		}
		else {
		a+=c[i];
		zd=max(zd,c[i]);
		}
		if(y==1){
		if(a>zd*2){
			zsq++;

			}
		}
		else as(i+1,y-1);a-=c[i];
	}return 0;
}
int main(){
	cin>>b;
	
	for(int i=1;i<=b;i++){
		cin>>c[i];
	}
	for(int i=3;i<=b;i++){
		as(1,i);
			}
cout<<zsq;
	return 0;
}