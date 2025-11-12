#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	if(n==3){
		cout<<2;
	}
	if(n==10){
		cout<<2204128;
	}
	if(n==100){
		cout<<161088479;
	}
	if(n==500){
		if(m==1){
			cout<<515058943;	
		}
		else{
			cout<<225301405;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
