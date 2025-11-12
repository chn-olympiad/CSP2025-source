#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b[a.length()];
	for(int i=0;i<a.length();i++){
	b[i]=-1;
	}	
	for(int i=0;i<a.length();i++){
		
		if(a[i]-'0'>=0&&a[i]-'0'<=9)
		b[i]=int(a[i]-'0');
		
	}
	for(int i=0;i<a.length();i++){
		for(int j=0;j<a.length()-i-1;j++){
		if(b[j]<b[j+1]) swap(b[j],b[j+1]);
	}
	}
	for(int i=0;i<a.length();i++){
		if(b[i]==-1) continue;
		cout<<b[i];
	}
} 
