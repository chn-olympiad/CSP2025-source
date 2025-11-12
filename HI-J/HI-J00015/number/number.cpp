#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	int a[n];
	char b[n]; 
	for(int i=0;i<n;i++){
		a[i]=s[i];
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<=9;j++){
			if(j==char(a[i])){
				int l=j;
				a[i]=l;
			}
		} 
	}
	int m=b[0],p=m;
	for(int i=0;i<n;i++){
		if(0<=char(a[i])<=9){
		b[i]=char(a[i]);	
		for(int j=0;j<n;j++){
			if(m<char(b[j])){
			m=char(b[j]);
						
			cout<<char(m)<<" ";
		}
		
		}
	}}
	fclose(stdin);
	fclose(stdout);
	return 0;

}
