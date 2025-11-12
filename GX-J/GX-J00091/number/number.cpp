#include<bits/stdc++.h>
using namespace std;
string s;
int x[1000005];
int n,e;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int b=s.size();
	if(b==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<b;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			if(s[i]=='1') x[n]=1;
			if(s[i]=='2') x[n]=2;
			if(s[i]=='3') x[n]=3;
			if(s[i]=='4') x[n]=4;
			if(s[i]=='5') x[n]=5;
			if(s[i]=='6') x[n]=6;
			if(s[i]=='7') x[n]=7;
			if(s[i]=='8') x[n]=8;
			if(s[i]=='9') x[n]=9;
			if(s[i]=='0') x[n]=0;
			n++;
		}
	}
	for(int j=0;j<n;j++){
		for(int i=0;i<n;i++){
			if(x[i-1]<x[i]&&i!=0) e=x[i],x[i]=x[i-1],x[i-1]=e;
		}
	}
	for(int i=0;i<n;i++){
		cout<<x[i]<<' ';
	}
	return 0;
}
