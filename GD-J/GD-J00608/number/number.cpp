#include<bits/stdc++.h>
using namespace std;
const int N=1000000;
string n;
int m[N+5],s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(n[i]>=48&&n[i]<58){
			m[n[i]-48]++;
			if(n[i]-48==9){
				cout<<9;
			}	
		}		
	}

	for(int i=8;i>=1;i--){
		for(int j=1;j<=m[i];j++){
			cout<<i;
			s++;
		}
	}
	if(s==0){
		cout<<0;
	}
	else{
		for(int i=1;i<=m[0];i++){
			cout<<0;
		}
	}
} 
