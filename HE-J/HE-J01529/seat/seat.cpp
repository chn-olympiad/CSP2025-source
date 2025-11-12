#include<bits/stdc++.h>
using namespace std;
long long a[114],t[114],b,x,y,c;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>x>>y;
	b=x*y;	
	for(int i=1;i<=b;i++){
		cin>>a[i];
		if(a[1]<a[i])c++;
	}
	//cout<<c;
	for(int i=1;;i++){
		for(int u=1;u<=y;u++){
			if(c==0){
				cout<<i<<" "<<u;
				return 0;
			}
			c--;
		}i++;
		for(int u=y;u>=1;u--){ 
			if(c==0){
				cout<<i<<" "<<u;
				return 0;
			}
			c--;
		}} 
	
	
	
	return 0;
}
