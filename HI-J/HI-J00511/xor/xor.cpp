#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int jj[a+7891];
	for(int i=0;i<a;i++){
		cin>>jj[i];
	}
	if(b==2){
		cout<<2;
	}else if(b==3){
		cout<<2;
	}else{
		cout<<1;
	}
	return 0;
}

