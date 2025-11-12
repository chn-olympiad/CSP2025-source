#include<bits/stdc++.h>
using namespace std;
struct a{
	int b1,b2,b3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,sum=0,b1=0,b2=0,b3=0;
	cin>>n;
	a b[n];
	for(int i=0;i<n;i++){
		cin>>b[i].b1>>b[i].b2>>b[i].b3;
	}
	for(int i=0;i<n;i++){
		if(i==1){
			b1=b[i].b1;
			b2=b[i].b2;
			b3=b[i].b3;
			continue;
		}
	    if(b[i].b1>b1){
			b1=b[i].b1;	
	}
		if(b[i].b2>b2){
			b2=b[i].b2;	
	}
	if(b[i].b3>b3){
			b3=b[i].b3;	
	}
}
	sum=b1+b2+b3;
	cout<<sum;
	return 0;
}
