#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a0=0;
	string a;
	std::cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]=='0'){
			a0++;
		}
		if(a[i]=='1'){
			a1++;
		}
		if(a[i]=='2'){
			a2++;
		}
		if(a[i]=='3'){
			a3++;
		}
		if(a[i]=='4'){
			a4++;
		}
		if(a[i]=='5'){
			a5++;
		}
		if(a[i]=='6'){
			a6++;
		}
		if(a[i]=='7'){
			a7++;
		}
		if(a[i]=='8'){
			a8++;
		}
		if(a[i]=='9'){
			a9++;
		}
	}
	while(a9--){
		std::cout<<9;
	}
	while(a8--){
		std::cout<<8;
	}
	while(a7--){
		std::cout<<7;
	}
	while(a6--){
		std::cout<<6;
	}
	while(a5--){
		std::cout<<5;
	}
	while(a4--){
		std::cout<<4;
	}
	while(a3--){
		std::cout<<3;
	}
	while(a2--){
		std::cout<<2;
	}
	while(a1--){
		std::cout<<1;
	}
	while(a0--){
		std::cout<<0;
	}
	return 0;
} 
