#include<bits/stdc++.h>
using namespace std;
int N=1000010;
long long slen(string a){
	string m;
	for(long long i=1;i<N;i++){
		for(int j=0;j<i;j++){
			m=m+a[j];
			
			}
			if(m==a){
				int alen=i;
				return alen;
				}
			m="";
		}
	return 0;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    
    string s,m;
    cin>>s;
    if(s=="0"){
		cout<<0;
		return 0;
		}
	if(s=="1"){
		cout<<1;
		return 0;
		}
	if(s=="2"){
		cout<<2;
		return 0;
		}
	if(s=="3"){
		cout<<3;
		return 0;
		}
	if(s=="4"){
		cout<<4;
		return 0;
		}
	if(s=="5"){
		cout<<5;
		return 0;
		}
	if(s=="6"){
		cout<<6;
		return 0;
		}
	if(s=="7"){
		cout<<7;
		return 0;
		}
	if(s=="8"){
		cout<<8;
		return 0;
		}
	if(s=="9"){
		cout<<9;
		return 0;
		}
	int f=0;
    long long n[N]={};
    for(long long i=0;i<slen(s);i++){
		if(s[i]=='0'){
			n[f]=0;
			f++;
			}
		if(s[i]=='1'){
			n[f]=1;
			f++;
			}
		if(s[i]=='2'){
			n[f]=2;
			f++;
			}
		if(s[i]=='3'){
			n[f]=3;
			f++;
			}
		if(s[i]=='4'){
			n[f]=4;
			f++;
			}
		if(s[i]=='5'){
			n[f]=5;
			f++;
			}
		if(s[i]=='6'){
			n[f]=6;
			f++;
			}
		if(s[i]=='7'){
			n[f]=7;
			f++;
			}
		if(s[i]=='8'){
			n[f]=8;
			f++;
			}
		if(s[i]=='9'){
			n[f]=9;
			f++;
			}
		}
	for(int i=0;i<f-1;i++){
		for(int j=0;j<f-1;j++){
			    if(n[j]<n[j+1]){
					int temp=n[j];
					n[j]=n[j+1];
					n[j+1]=temp;
					}
			    
			}
		}
	for(int i=0;i<f;i++){
		cout<<n[i];
		}
		
	
	
    
    
    return 0;
}
