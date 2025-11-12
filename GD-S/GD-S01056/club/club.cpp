#include<iostream>
using namespace std;
int t,n;
int zm=0;
int jh(int a[n],int b[n],int c[n],int am,int bm,int cm,int zm,int ar,int br,int cr,int r){
	if(r=n){
		if(am+bm+cm>zm){
			zm=am+bm+cm;
			return 0;
		}
	}
	if(ar<n/2){
		jh(a[n],b[n],c[n],am+a[r],bm,cm,ar+1,br,cr,r+1);
	}
	if(ar<n/2){
		jh(a[n],b[n],c[n],am,bm+b[r],cm,ar,br+1,cr,r+1);
	}
	if(ar<n/2){
		jh(a[n],b[n],c[n],am,bm,cm+c[r],ar,br,cr+1,r+1);
	}
}
int main(){
	
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		int a[n]=0,b[n]=0,c[n]=0;
		for(int x=0;x<n;x++){
			cin>>a[x];
			cin>>b[x];
			cin>>c[x];
		}
		int am=0,bm=0,cm=0;
		int ar=0,br=0,cr=0;
		jh(a[n],b[n],c[n],am,bm,cm,ar,br,cr,0);
	}
	return 0;
}
