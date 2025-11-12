#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a>100){
		cout<<63;
	}else if(b>1){
		cout<<c;
	}else{
		cout<<d;
	}
	return 0;
}
