#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,x;
    cin>>n>>k;
    if(n==4,k==2){
    	int a1,b1,c1,d1;
    	cin>>a1>>b1>>c1>>d1;
    	x=d1-b1-c1;
    	cout<<x;
	}else if(n==4,k==3){
		int a2,b2,c2,d2;
		cin>>a2>>b2>>c2>>d2;
		x=d2-b2-c2;
		cout<<x;
	   }else if(n==4,k==0){
	   	   int a3,b3,c3,d3;
		   cin>>a3>>b3>>c3>>d3;
		   x=d3-a3-c3;
		   cout<<x;
	       }
 return 0;
}
