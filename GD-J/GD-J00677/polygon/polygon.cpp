#include<iostream>
#include<cstring>
using namespace std;
int a[1000005];
int main(){
	fropen("polygon.in","r",strin);
    fropen("polygon.out","w",strout);
    int b,maxx=0,x,n=0;
    cin>>b;
    for(int i=1;i<=b;i++){
    	cin>>a[i];
	}
	for(int i=2;i<=b;i++){
		for(int j=1;j<=b-i;j++){
			x=0;
			for(int v=j;v<=j+i;v++){
				x+=a[v];
				if(a[v]>=maxx){
					maxx=a[v];
				}
			}
			if(maxx*2<x){
				n+=1;
			}
			maxx=0;
		}
	}
	cout<<n;
    return 0;
} 
