#include<bits/stdc++.h>
using namespace std;
int a,b,c[10000000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	srand(1);
	int d=1; 
	for(int i=0;i<a;i++){
		cin>>c[i];
		if(c[i]==0){
			d=0;
		}
	}if(d==1){
		cout<<1;
	}else{
		cout<<2;
	}
	return 0;
}
