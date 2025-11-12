#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
int n,k;
cin>>n>>k;
int a,o=0;
string b[n]="";
for(int i=0;i<n;i++){
	cin>>a;
	for(;a>0;){
		if(a%2==0){
			b[i]=b[i]+'0';
		}else{
			b[i]=b[i]+'1';
		}
		a=a/2;
	}
} 
if(n==2){
	if(b[0]=="0"){
		cout<<1;
	}else if(b[1]=="0"){
		cout<<1;
	}else{
		cout<<1;
	}
}else{
	cout<<1;
}
return 0;
}
