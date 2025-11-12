#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int l=0;
	int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
	cin>>s;
	while(s[l]!=0){
		l++;
	}
	for(int i=0;i<=l;i++){
		if(s[i]==48)n0++;
		if(s[i]==49)n1++;
		if(s[i]==50)n2++;
		if(s[i]==51)n3++;
		if(s[i]==52)n4++;
		if(s[i]==53)n5++;
		if(s[i]==54)n6++;
		if(s[i]==55)n7++;
		if(s[i]==56)n8++;
		if(s[i]==57)n9++;
		if(s[i]==0)break;
	}
	for(int i=0;i<n9;i++)cout<<"9";
	for(int i=0;i<n8;i++)cout<<"8";
	for(int i=0;i<n7;i++)cout<<"7";
	for(int i=0;i<n6;i++)cout<<"6";
	for(int i=0;i<n5;i++)cout<<"5";
	for(int i=0;i<n4;i++)cout<<"4";
	for(int i=0;i<n3;i++)cout<<"3";
	for(int i=0;i<n2;i++)cout<<"2";
	for(int i=0;i<n1;i++)cout<<"1";
	for(int i=0;i<n0;i++)cout<<"0";
	return 0;
} 
