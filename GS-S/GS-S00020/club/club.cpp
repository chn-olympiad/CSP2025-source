#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int a,b,c,d,e,f,m,n;
	int s=m+n;
	    if(a>b>c){
	    a==m;
	    return 0;
	    }
	    if(a>c>b){
		a==m;
		return 0;	
	    }
	    if(b>a>c){
        b==m;
		return 0; 
	    }
	    if(b>c>a){
	    b==m;
		return 0;
	    }
	    if(c>a>b){
		c==m;
		return 0;
     	}
	    if(c>b>a){
		c==m;
		return 0;
	    }
	    if(d>e>f){
	    d==n;
	    return 0;
	    }
	    if(d>f>e){
		d==n;
		return 0;	
     	}
	    if(f>e>d){
        f==n;
		return 0;} 

  	    if(f>d>e){
		f==n;
		return 0;
	    }
	    if(e>f>d){
		e==n;
		return 0;
	    }
	    if(e>d>f){
		e==n;
		return 0;
	    }
      return s;

	return 0;
}

