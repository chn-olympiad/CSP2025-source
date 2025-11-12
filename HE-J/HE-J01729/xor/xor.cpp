#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int a,k,d=0,e=0;
	double c;
	cin>>a,k;
	c=a;
	int s[a];
	for(int i=0;i<a;i++){
		cin>>s[i];}
	if(a<c/2){
		for(int i=0;i<k;i++){
			d=s[i]^d;}
		for(int i=k;i<a;i++){
			e=s[i]^e;}
		cout<<max(d,e);}
	else{
		for(int i=0;i<k-1;i++){
			d=s[i]^d;}
		for(int i=k-1;i<a;i++){
			e=s[i]^e;}
		cout<<max(d,e);}
	
	return 0;}
