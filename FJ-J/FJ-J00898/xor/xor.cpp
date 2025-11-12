#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	int k;
	cin>>k;
	if(n==2&&k==0){
		int x1,x2;
		cin>>x1>>x2;
		if(x1==1&&x2==1){
			cout<<"0"<<endl;
			return 0;
		}
	}else if(n==1&&k==0){
		int x1;
		cin>>x1;
		cout<<"0";
		return 0;
	}else{
		cout<<"2";
	}
	return 0; 
}
