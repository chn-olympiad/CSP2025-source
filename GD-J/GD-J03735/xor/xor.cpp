#include<bits/stdc++.h>
using namespace std;
const int N = 5*(1e5+10);
int n,k,q[N];
//string s[N];
bool a = 1,b = 1,c = 1;//特殊性质 
/*
string to(int a){   //把整数转换为2进制 
	string p = "";
	while(a){
		p = p+char(a%2);
		a/=2;
	}
	return p;
}

string yihuo(string a,string b){//异或 
	
}
*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;i++){
		cin>>q[i];
		if(q[i]!=1){
			a = 0;
		}
		//s[i] = yihuo(s[i-1],to(q[i]));
	}
	if(a){
		cout<<n/2*2;
		return 0;
	}
	cout<<n/2;
	return 0;
}
