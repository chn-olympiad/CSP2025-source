#include <bits/stdc++.h> 
using namespace std;

int main(){
	//feropen(".in","r",stdin);
	//feropen(".out","w",stdout);
	int a[2^20],b,c,d;
	cin>>b>>c;
	for(int i=0;i<b;i++){
		cin>>a[i];
	}
	for(int i=0;i<b;i++){
		while(a[i]&&1){
			cout<<a[i];
			break;
		}
	}
	
}
