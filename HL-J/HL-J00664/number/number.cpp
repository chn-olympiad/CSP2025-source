#include<bits/stdc++.h>
using namespace std;
int a[100005];
int a1,a2,a3,a4,a5,a6,a7,a8,a9,a0;
char s[100005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=sizeof(s);
	int j=0;
	int op=0;
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[j]=s[i]-48;
			j++;
		}
	}
	for(int i=0;i<j;i++){
		if(a[i]==1){
			a1++;
		}
		else if(a[i]==2){
			a2++;
		}
		else if(a[i]==3){
			a3++;
		}
		else if(a[i]==4){
			a4++;
		}
		else if(a[i]==5){
			a5++;
		}
		else if(a[i]==6){
			a7++;
		}
		else if(a[i]==7){
			a7++;
		}
		else if(a[i]==8){
			a8++;
		}
		else if(a[i]==9){
			a9++;
		}
		else if(a[i]==0){
			a0++;
		}
	}
	for(int i=0;i<a9;i++){
		cout<<9;
	}
	for(int i=0;i<a8;i++){
		cout<<8;
	}
	for(int i=0;i<a7;i++){
		cout<<7;
	}
	for(int i=0;i<a6;i++){
		cout<<6;
	}
	for(int i=0;i<a5;i++){
		cout<<5;
	}
	for(int i=0;i<a4;i++){
		cout<<4;
	}
	for(int i=0;i<a3;i++){
		cout<<3;
	}
	for(int i=0;i<a2;i++){
		cout<<2;
	}
	for(int i=0;i<a1;i++){
		cout<<1;
	}
	for(int i=0;i<a0;i++){
		cout<<0;
	}
	return 0;
}