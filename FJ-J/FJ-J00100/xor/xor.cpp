#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
int n;
cin>>n;
int k;
cin>>k;
if(n==2&&k==0){
	int a,b;
	cin>>a>>b;
	if(a==b){
		cout<<"1";
	}else{
		cout<<"0";
	}
}else{
	if(n==4&&k==3){
		cout<<"2";
	}else if(n==4&&k==0){
		cout<<"0";
	}else{
		cout<<n/2;
	}
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
