#include<bits/stdc++.h>
using namespace std;
string s,b;
long long int a[1000]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		b=s.substr(i,1);
		if(b=="1"){
			a[1]+=1;
		}else if(b=="2"){
			a[2]+=1;
		}else if(b=="3"){
			a[3]+=1;
		}else if(b=="4"){
			a[4]+=1;
		}else if(b=="5"){
			a[5]+=1;
		}else if(b=="6"){
			a[6]+=1;
		}else if(b=="7"){
			a[7]+=1;
		}else if(b=="8"){
			a[8]+=1;
		}else if(b=="9"){
			a[9]+=1;
		}else if(b=="0"){
			a[10]+=1;
		}
	}
	if(a[9]!=0){
		for(int i=1;i<=a[9];i++){
			cout<<'9';
		}
	}
	if(a[8]!=0){
		for(int i=1;i<=a[8];i++){
			cout<<'8';
		}
	}
	if(a[7]!=0){
		for(int i=1;i<=a[7];i++){
			cout<<'7';
		}
	}
	if(a[6]!=0){
		for(int i=1;i<=a[6];i++){
			cout<<'6';
		}
	}
	if(a[5]!=0){
		for(int i=1;i<=a[5];i++){
			cout<<'5';
		}
	}
	if(a[4]!=0){
		for(int i=1;i<=a[4];i++){
			cout<<'4';
		}
	}
	if(a[3]!=0){
		for(int i=1;i<=a[3];i++){
			cout<<'3';
		}
	}
	if(a[2]!=0){
		for(int i=1;i<=a[2];i++){
			cout<<'2';
		}
	}
	if(a[1]!=0){
		for(int i=1;i<=a[1];i++){
			cout<<'1';
		}
	}
	if(a[10]!=0){
		for(int i=1;i<=a[10];i++){
			cout<<'0';
		}
	}
	return 0;
} 
