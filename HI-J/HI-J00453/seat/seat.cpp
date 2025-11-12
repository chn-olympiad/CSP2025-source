#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,w,w1,z,c,h;
	cin>>x>>y;
	a[0]=0;
	cin>>x>>y;
	for(int i=1;i<=x*y;i++){
		cin>>a[i];
		w1=a[1];
		for(int k=1;k<=x*y;k++){
			w=max(a[i],a[i-1]);
			if(w==a[i])swap(a[i],a[i-1]);
		}
	}
	for(int i=0;i<x*y;i++){
		if(a[i]==w1)z=i+1;
	}
	for(int i=0;i<x*y;i++){
		
	}
	return 0;

}
