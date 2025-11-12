#include<bits/stdc++.h>
using namespace std;
int a[200];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,x,y,f=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
    	cin>>a[i];
    	if(a[i]>=a[1]){
    		f++;
		}
	}
	int tem=f%n;
	x=f/n+1;
	if(tem==0){
		x=f/n;
		if(x%2==0){
			y=1;
		}else{
			y=n;
		}
	}
	else if(x%2==0){
			y=n-tem+1;
	}else{
			y=tem;
	}
	cout<<x<<" "<<y;
    return 0;
}

