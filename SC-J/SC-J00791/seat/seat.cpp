#include<bits/stdc++.h> 
using namespace std;
int main(){
	
	long long a,b,r,p,l,h;
	cin>>a>>b;
	int c[a*b];
	cin>>r;
	c[0]=r;
	for(int i=1;i<a*b;i++){
		cin>>c[i];
	}sort(c,c+a*b);
	for(int i=0;i<a*b;i++){
		if(c[i]==r){
			p=a*b-i;

			break;
		}}
	l=p/a;
	h=p%a;
	if(h!=0){
		l=l+1;
	}
	else{
		h=a;
	}
	if(l%2==0){
		h=a-h+1;
}
cout<<l<<" "<<h;
	return 0;
}