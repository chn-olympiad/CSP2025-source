#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string n;
	cin>>n;
	long long a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0,a9=0,a0=0;
	for(int i=0; i < n.size() ; i++){
		char k = n[i];
		if(k == '0') a0++;
		if(k == '1') a1++;
		if(k == '2') a2++;
		if(k == '3') a3++;
		if(k == '4') a4++;
		if(k == '5') a5++;
		if(k == '6') a6++;
		if(k == '7') a7++;
		if(k == '8') a8++;
		if(k == '9') a9++;
	}
	for(int i=0;i<a9;i++)cout<<9;
	for(int i=0;i<a8;i++)cout<<8;
	for(int i=0;i<a7;i++)cout<<7;
	for(int i=0;i<a6;i++)cout<<6;
	for(int i=0;i<a5;i++)cout<<5;
	for(int i=0;i<a4;i++)cout<<4;
	for(int i=0;i<a3;i++)cout<<3;
	for(int i=0;i<a2;i++)cout<<2;
	for(int i=0;i<a1;i++)cout<<1;
	for(int i=0;i<a0;i++)cout<<0;
	return 0;
}
