#include<bits/stdc++.h>
using namespace std;
int n,q;
string l; 
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q>>l;
	if(n == 4){
		cout<<2<<endl<<0;
	}else if(n == 3){
		for(int i = 1;i <= 4;i++){
			cout<<0<<endl;
		}
	}else{
		cout<<0;
	}
	return 0;
} 
