#include<bits/stdc++.h>
#include<cstring>
using namespace std;
string s;
int main(){
	int r=0;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s; 
	int a[100001],j=0;
	memset(a,0,sizeof(a));
/*	for(int i=0;i<=sizeof(s);i++){
		if(s[i]<"a"){
			if(s[i]=="0"){
				a[j]=0;
				j++;
			}
			if(s[i]=="1"){
				a[j]=1;
				j++;
			}
			if(s[i]=="2"){
				a[j]=2;
				j++;
			}
			if(s[i]=="3"){
				a[j]=3;
				j++;
			}
			if(s[i]=="4"){
				a[j]=4;
				j++;
			}
			if(s[i]=="5"){
				a[j]=5;
				j++;
			}
			if(s[i]=="6"){
				a[j]=6;
				j++;
			}
			if(s[i]=="7"){
				a[j]=7;
				j++;
			}
			if(s[i]=="8"){
				a[j]=8;
				j++;
			}
			if(s[i]=="9"){
				a[j]=9;
				j++;
			}
		}*/
		for(int i=0;i<=sizeof(s);i++){
			a[i]=s[i];
			j++;
		}
	for(int q=0;q<=j;q++){
		for(int w=q;w<j;w++){
			if(s[w]<s[w+1]){
				swap(s[w],s[w+1]);
				}
			}
		}
		
	for(int e=0;e<=j;e++){
			if(s[e]=='0'){
				cout<<0;
			}
			if(s[e]=='1'){
				cout<<1;
			}
			if(s[2]=='2'){
				cout<<2;
			}
			if(s[e]=='3'){
				cout<<3;
			}
			if(s[e]=='4'){
				cout<<4;
			}
			if(s[e]=='5'){
			cout<<5;
			}
			if(s[e]=='6'){
				cout<<6;
			}
			if(s[e]=='7'){
				cout<<7;
			}
			if(s[e]=='8'){
				cout<<8;
			}
			if(s[e]=='9'){
				cout<<9;
			}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
