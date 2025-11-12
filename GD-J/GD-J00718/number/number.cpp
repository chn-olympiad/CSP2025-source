#include<bits/stdc++.h>
using namespace std;

int main(){
	sreopen("number.in","r",stdin);
	sreopen("number.out","w",stdout);
	string s;
	int m,n,a=10,b=1000,c=1000000;
	cin>>s;
	for(int i=0;i<=a;i++){
		
		if(s[i]<10&&s[i]>0){
			n++;
		}else{
			m++;
		}
	}
	
	if(n=1){
		cout<<s;
	}
	if(n>b){
		cout<<"Êý×Ö³¬±ê"; 
	}
	if(n+m>c){
		cout<<"×Ö·û³¬±ê"; 
	}

	sclise(stdin);
	sclise(stdout);
	return 0;
} 
