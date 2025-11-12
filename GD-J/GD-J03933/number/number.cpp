#include <bits/stdc++.h>
using namespace std;
string s;
int ans,n,a[100007]={},p=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<=n;i++){
	if(s.substr(i,1)=="0"){
	p++;a[p]=0;}
	else if(s.substr(i,1)=="1"){
	p++;a[p]=1;}
	else if(s.substr(i,1)=="2"){
	p++;a[p]=2;}
	else if(s.substr(i,1)=="3"){
	p++;a[p]=3;}
	else if(s.substr(i,1)=="4"){
	p++;a[p]=4;}
	else if(s.substr(i,1)=="5"){
	p++;a[p]=5;}
	else if(s.substr(i,1)=="6"){
	p++;a[p]=6;}
	else if(s.substr(i,1)=="7"){
	p++;a[p]=7;}
	else if(s.substr(i,1)=="8"){
	p++;a[p]=8;}
	else if(s.substr(i,1)=="9"){
	p++;a[p]=9;}
}
	sort(a+1,a+p+1);
	for(int i=p;i>=1;i--) cout<<a[i];
	return 0;
}
