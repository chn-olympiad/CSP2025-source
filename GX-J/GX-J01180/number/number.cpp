#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	string b;
	cin>>a;
	for(int i=0;i<a.size;i++){
		if(a[i]==0){
		b[i]==0;
		}else if(a[i]==1){
		b[i]==1;
		}else if(a[i]==2){
		b[i]==2;
		}else if(a[i]==3){
		b[i]==3;
		}else if(a[i]==4){
		b[i]==4;
		}else if(a[i]==5){
		b[i]==5;
		}else if(a[i]==6){
		b[i]==6;
		}else if(a[i]==7){
		b[i]==7;
		}else if(a[i]==8){
		b[i]==8;
		}else if(a[i]==9){
		b[i]==9;
		}
	}
	for(int i=0;i<b.size;i++){
		for(int j=b.size-1;j!=0;j--){
			if(b[i]<b[j]){
				b[i]==b[j];
				b[j]==b[i];
			}
		}	
	}
	cout<<b<<" ";
}
