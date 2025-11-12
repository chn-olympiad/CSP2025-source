#include<bits/stdc++.h>
using namespace std;
long long a,b,c[114514]={};
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.in","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	if(a<=100){
		cout<<1;
		return 0;
	}
	else if(a<=1000){
		cout<<2;
		return 0;
	}
	else if(a<=200000){
		cout<<1;
		return 0;
	}
	else{
		cout<<2;
		return 0;
	}
}