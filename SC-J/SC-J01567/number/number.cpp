#include<bits/stdc++.h> 
using namespace std;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;cin>>s;
	int t=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9')a[++t]=s[i]-48;
	}
	
	for(int i=t;i>=1;i--){
		if(a[i]==9)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==8)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==7)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==6)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==5)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==4)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==3)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==2)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==1)cout<<a[i];
	}
	for(int i=t;i>=1;i--){
		if(a[i]==0)cout<<a[i];
	}
	return 0;
}