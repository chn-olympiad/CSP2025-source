#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c,r,x,a,s[101];
	cin>>c>>r;
	a=c*r;
	int b1=1,b2=1;
	for(int i=0;i<a;i++){
		cin>>s[i];
	}
	x=s[0];
	for(int i=0;i<a;i++){
		if(b1%2==1){
			if(s[i]>x){
				b2++;
				if(b2>r){
					b1+=1;
					b2--;
				}
				if(b2<1){
					b1++;
					b2++;
				}
			}	
		}else{
			if(s[i]>x){
				b2--;
				if(b2>r){
					b1+=1;
				}
				if(b2<1){
					b1++;
					b2++;
				}
			}	
		}
		
	}
	cout<<b1<<" "<<b2;
	return 0;
}
