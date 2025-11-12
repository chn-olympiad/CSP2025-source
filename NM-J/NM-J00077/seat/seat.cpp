#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long int a,b,c,x,y,h,x1=0,y1=0;
    cin>>x>>y;
    long long int z[x*y];
    for(int i=0;i<x*y;i++){
    cin>>z[i];
    }
    a=z[0];
    for(int i=0;i<x*y;i++){
    for(int j=0;j<i;j++){
        if(z[j]<z[j+1]){
            h=z[j];
            z[j]=z[j+1];
            z[j+1]=h;
        }
    }}
    for(int i=1;i<=x*y;i++){
    if(z[i-1]==a){
        if(i/y%2==1){
            x1=i/x;
            y1=i/y;
			cout<<i/x;
        }

        if(i/y%2==0){
            x1=x-i%x;
            y1=i/y;
        }
    }
    }
    if(x1==0){
    	x1=1;
	}
	if(y1==0){
    	y1=1;
	}
    cout<<x1<<"\n"<<y1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
