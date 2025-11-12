#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,b,c,d,e,m,n,r;
	cin>>m>>n>>a>>b>>d>>e;
	int h=0;
	h=h+1;
	if(a>b){
		h++;
	}
	if(a>d){
		h++;
	}
	if(a>e){
		h++;
	}
	c=h/n;
	if(c%2==0){
		r=n-(h%n);
	}
	else if(c%2==1){
		r=h%n;
	}
	cout<<c<<" "<<r;
    return 0; 
}
