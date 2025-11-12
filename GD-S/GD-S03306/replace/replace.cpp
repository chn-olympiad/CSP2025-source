#include<stdio.h>
#include<iostream>
#include<string>
#include<cmath>
#include<ostream>
#include<bits/stdc++.h>
using namespace std; 
int n,q;
string a[200001][2];
string b[200001][2];
int co(string s1,string s2){
	int ans=0;
	string s;
	for(int i=1;i<s1.size();i++){
		if(s1[i]!=s2[i]){
			s+=s1[i]; 
		}
	}
	for(int i=n+1;i<=q;i++){
		if(s==a[i][1]){
			ans++;
		}
		if(s==a[i][2]){
			ans++;
		}
		for(int i1=1;i<s1.size();i1++){
		string temp;
		for(int j=i;j<s1.size();j++){
			temp+=s1[j];
			if(temp==a[i][1]){
				ans++;
			}
			if(temp==a[i][2]){
				ans++;
			}
		}
	}
	}
	return ans;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int sum=0;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	for(int j=1;j<=q;j++){
		b[j][1]=a[j+n+1][1];
		b[j][2]=a[j+n+1][2];
		cout<<co(b[j][1],b[j][2])<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}







































