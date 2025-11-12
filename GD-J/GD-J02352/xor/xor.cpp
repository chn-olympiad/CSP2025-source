#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	if(n==1){
		int a;
		cin>>a;
		if(a==0){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if(n==2){
		int a,b;
		cin>>a>>b;
		if(a==0&&b==0){
			cout<<"2";
		}
		else if(a==0||b==0){
			cout<<"";
		}
		else if(a==b){
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==k&&b==k&&c==k){
			cout<<"3";
		}
		else if(a==k&&b==k){
			cout<<"2";
		}
		else if(c==k&&b==k){
			cout<<"2";
		}
		else if(a==k&&c==k){
			cout<<"2";
		}
		else if(a==k&&b^c==k){
			cout<<"2";
		}
		else if(c==k&&b^a==k){
			cout<<"2";
		}
		else if(b==k&&c^a==k){
			cout<<"2";
		}
		else if(a==k||b==k||c==k){
			cout<<"1";
		} 
		else{
			cout<<"0";
		}
	}
	return 0;
} 
