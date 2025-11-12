#include<iostream>
using namespace std;
int m=0;
int n=0;
int c=1;
int r=0;
int abc[105];
int abcd[105];
int b=1;
int d=0;
int l=0;
int v=0;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>abc[i];
	}
	b=n*m;
	for(int a=1;a<=b;a++){
		if(abc[a]>abc[a+1]){
			d=abc[a];
			abc[a+1]=c;
			abc[a]=abc[a+1];
			abcd[a]=abc[a];
			}
			
			if(abc[a]<abc[a+1]){
			d=abc[a+1];
			abc[a]=c;
			abc[a+1]=abc[a];
			abcd[a]=abc[a+1];
		}
	}
		for(int b=1;b<=100;b++){
		}
}
	
