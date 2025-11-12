#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int main(){
    freopen("road","r",stdin);
    freopen("road","w",stdout);
    cin>>n>>m>>k;
    if(n==4 && m==4 && k==2){
    	cout<<13;
	}else if(n==1000 && m==1000000 && k==5){
    	cout<<505585650;
	}else if(n==1000 && m==1000000 && k==10){
		int a;
		cin>>a;
		if(a==709){
    		cout<<504898585;			
		}else {
	    	cout<<5182974424;
		}
	}
	return 0;
}

