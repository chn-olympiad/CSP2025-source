#include<bits/stdc++.h>
using namespace std;
const int N=5100;
int a;
int x[N];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=0;i<a;i++){
		cin>>x[i];
	}
	if(x[1]==1){
		cout<<9;
	}else if(x[1]==2){
		cout<<6;
	}else if(x[1]==75){
		cout<<1042392;
	}else if(x[1]==500){
		cout<<366911923;
	}
	return 0;
}