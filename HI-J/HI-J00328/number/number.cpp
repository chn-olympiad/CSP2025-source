#include<bits/stdc++.h>
using namespace std;
string s;
char a[1000005];
int n[1000005];
int main(){
	cin>>s;
	for(int i=0;i<s.length();i++){
		a[i+1]=s[i];
	}
	int ni=0,n0=0;
	for(int i=1;i<=s.length();i++){
		if(a[i]=='0'){
			n0++;
		}
		if(a[i]=='1'){
			ni++;
			n[ni]=1;
		}
		else if(a[i]=='2'){
			ni++;
			n[ni]=2;
		}
		else if(a[i]=='3'){
			ni++;
			n[ni]=3;
		}
		else if(a[i]=='4'){
			ni++;
			n[ni]=4;
		}
		else if(a[i]=='5'){
			ni++;
			n[ni]=5;
		}
		else if(a[i]=='6'){
			ni++;
			n[ni]=6;
		}
		else if(a[i]=='7'){
			ni++;
			n[ni]=7;
		}
		else if(a[i]=='8'){
			ni++;
			n[ni]=8;
		}
		else if(a[i]=='9'){
			ni++;
			n[ni]=9;
		}
	}
	while(1){
		bool f=0;
		for(int i=1;i<=ni;i++){
			if(n[i]>0) f=1;
		}
		if(f){
			int maxn=-1;
			int ii;
			for(int i=1;i<=ni;i++){
				if(n[i]>maxn){
					maxn=n[i];
					ii=i;
				}
			}
			cout<<maxn;
			n[ii]=0;
		}
		else{
			for(int i=1;i<=n0;i++){
				cout<<0;
			}
			break;
		}
	}
	return 0;
} 
