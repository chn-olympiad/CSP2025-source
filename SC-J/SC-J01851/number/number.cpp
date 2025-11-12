#include<bits/stdc++.h>
using namespace std;
string a;
int b0=0,b1=0,b2=0,b3=0,b4=0,b5=0,b6=0,b7=0,b8=0,b9=0;
int u=0;
int main()
{
	
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int n;
	n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]=='9'){
			b9++;
		}
		if(a[i]=='8'){
			b8++;
		}
		if(a[i]=='7'){
			b7++;
			
		}
		if(a[i]=='6'){
			b6++;
		}
		if(a[i]=='5'){
			b5++;
		}
		if(a[i]=='4'){
			b4++;
		}
		if(a[i]=='3'){
			b3++;
		}
		if(a[i]=='2'){
			b2++;
		}
		if(a[i]=='1'){
			b1++;
		}
		if(a[i]=='0'){
			b0++;
		}
	}
	if(b9!=0){
		u=1;
		for(int i=1;i<=b9;i++){
			cout<<9;
		}
	}
	if(b8!=0){
		u=1;
		for(int i=1;i<=b8;i++){
			cout<<8;
		}
	}
	if(b7!=0){
		u=1;
		for(int i=1;i<=b7;i++){
			cout<<7;
		}
	}
	if(b6!=0){
		u=1;
		for(int i=1;i<=b6;i++){
			cout<<6;
		}
	}
	if(b5!=0){
		u=1;
		for(int i=1;i<=b5;i++){
			cout<<5;
		}
	}
	if(b4!=0){
		u=1;
		for(int i=1;i<=b4;i++){
			cout<<4;
		}
	}
	if(b3!=0){
		u=1;
		for(int i=1;i<=b3;i++){
			cout<<3;
		}
	}
	if(b2!=0){
		u=1;
		for(int i=1;i<=b2;i++){
			cout<<2;
		}
	}
	if(b1!=0){
		u=1;
		for(int i=1;i<=b1;i++){
			cout<<1;
		}
	}
	if(u==1&&b0!=0){
		for(int i=1;i<=b0;i++){
			cout<<0;
		}
	}
	if(u==0){
		cout<<0; 
	}
	return 0;
    
 } 