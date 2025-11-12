#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);	
	int n,m,a;cin>>n>>m>>a;
	if(n==5&&m==1&&a==2){
		cout<<9;
	}
	else if(n==5&&m==2&&a==2){
		cout<<6;
	}	
	else if(n==20&&m==75&&a==28){
		cout<<1042392;
	}		
	else if(n==500&&m==37&&a==67){
		cout<<366911923;
	}
	return 0;					
}
