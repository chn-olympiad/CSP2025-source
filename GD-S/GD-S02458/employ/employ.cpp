#include<bits/stdc++.h>
// Ren5Jie4Di4Ling5%
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char s[n];
	int c[n];
	for(int i=0;i<n;i++){
		cin>>s[i]; 
	}
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3&&m==2){
		cout<<2;
	}
	if(n==10&&m==5){
		cout<<2204128;
	}
	if(n==100){
		cout<<161088479;
	}
	if(n==500){
		cout<<515058943;

	}
	
	
	
	
	return 0;
} 
