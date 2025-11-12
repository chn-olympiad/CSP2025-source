#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n=0,t=0,y=0,o=0;
	cin>>n;
	y=n;
	while(y>0){
	    y=y/10;
	    t++;
	}
	int a[t];
	int g=0;
	o=n;
	for(int i=0;i<t;i++){
		g=o%10;
		o=o/10;
		a[i]=g;
	}
	for(int j=0;j<t;j++){
	    for(int i=0;i<t;i++){
	    	int u=0;
		if(a[i]>a[i-1]){
			u=a[i];
			a[i]=a[i-1];
			a[i-1]=u;
	        }
	    }
	}
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	return 0;
}
