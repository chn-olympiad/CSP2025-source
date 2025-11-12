#include<bits/stdc++.h>
using namespace std;
int a=1,n,m,b,ls,zrs,c,d;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>b;
	zrs=n*m;
	for(int i=1;i<zrs;i++){
		cin>>ls;
		if(ls>b){
			a++;
		}
	}
	c=(a-1)/n+1;
	if(c%2){
		d=((a-1)%n)+1;
	}
	else{
		d=n-((a-1)%n);
	}
	cout<<c<<' '<<d;
	fclose(stdin);
	fclose(stdout);
} 
