#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char s[100000],a[1000000],d=0,c;
	for(int i=0;i<1000000;i++){
		s[i]='A';
	}
	cin>>s;
	for(int i=0;i<100000;i++){
		if(s[i]=='A'){
			break;
		}
		if(s[i]>=48&&s[i]<=57){
			a[d]=s[i];
			d++;
		}
	}
	for(int i=0;i<d;i++){
	    for(int j=i+1;j<d;j++){
		  if(a[i]<s[j]){
		  	c=s[i];
		  	s[i]=s[j];
		  	s[j]=c;
		  }
	   }
	}
	for(int i=0;i<d;i++){
		cout<<a[i];
	}
	return 0;
} 
