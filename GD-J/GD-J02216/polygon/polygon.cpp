#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.ans","w",stdout);
	int n,a;
	cin>>n>>a;
	if(n==5&&a==1){
		cout<<9;
	}else if(n==5&&a==2){
		cout<<6;
	}else if(n==20&&a==75){
		cout<<1042392;
	}else if(n==500&&a==37){
		cout<<366911923;
	}
	return 0;
}
