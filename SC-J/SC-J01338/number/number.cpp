#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	 string s;
 int a[100000],cnt=0;
	
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
		a[i]=0;cnt++;}
		if(s[i]=='1') {
		a[i]=1;cnt++;}
		if(s[i]=='2') {
		a[i]=2; cnt++;}
		if(s[i]=='3') {
		a[i]=3;cnt++;}
		if(s[i]=='4') {
		a[i]=4;cnt++;} 
		if(s[i]=='5'){
		a[i]=5;cnt++;}
		if(s[i]=='6') {
		a[i]=6; cnt++;}
		if(s[i]=='7') {
		a[i]=7;cnt++;}
		if(s[i]=='8') {
		a[i]=8;cnt++;}
		if(s[i]=='9') {
		a[i]=9;cnt++;} 
		}
         int c=s.size(); 
		for(int i=0;i<c;i++){
			for(int d=0;d<c;d++){
			if(a[i]<=a[d]) swap(a[i],a[d]);
			}	
		}
        for(int j=c-1;j>=c-cnt;--j){
       cout<<a[j];
       return 0; 
}
}