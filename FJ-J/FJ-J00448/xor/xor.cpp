#include <bits/stdc++.h>
using namespace std;
int a=0;
int b[200001];
int main(){
	freeopen("xor.in","r",stdin);
	freeopen("xor.out","w",stdout);
	int c,d;
	int ct=0;
	cin>>c>>d;
	for(int i=1;i<=c;i++){
		cin>>b[i];
	}
	for(int i=1;i<=c;i++){
		if(b[i]==0){
			a++;
		}
	}
	if(a==0){
		cout<<c;
		return 0;
	}
	else{
		for(int i=1;i<=c;i++){
			if(b[i]==0){
				if(b[i-1]==1){
					b[i-1]=2;
					ct++;
					continue;
				}
				else if(b[i+1]==1){
					b[i+1]=2;
					ct++;
					continue;
				}
			}
		}
		if(d==0) cout<<c;
		else{
			cout<<ct;
		}
	}
	return 0;
} 
