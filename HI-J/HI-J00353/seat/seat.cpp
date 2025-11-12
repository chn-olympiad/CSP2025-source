#include<bits/stdc++.h>
using namespace std ;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int x,y,n,a=1,b=1,c=1;
	cin>>x>>y>>n;
	int m[x*y];
	for(int i=1;i<x*y;i++){
		cin>>m[i];
	}
	for(int i=1;i<x*y;i++){
		if(n<m[i]){
			a+=c;
		}
		if(a>x||a<1){
			b=b+1;
			a-=c;
			c=-1*c;
		}
	}
	cout<<b<<" "<<a;
	return 0;
} 
