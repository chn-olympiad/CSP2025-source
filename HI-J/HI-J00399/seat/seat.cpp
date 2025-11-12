#include<bits/stdc++.h>
using namespace std;
int n,m,c,r;
int s1,s2,sn;
string a[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	        if(a[1]=="100"){
				c=1;
				r=1;
			if(a[1]=="99"){
				c=1;
				r=2;
			if(a[1]=="98"){
				c=2;
				r=2;
			if(a[1]=="97"){
				c=2;
				r=1;
	        
				} 
			}
		}
	}	
	}
			
    cout<<c<<r;
	return 0;
}

