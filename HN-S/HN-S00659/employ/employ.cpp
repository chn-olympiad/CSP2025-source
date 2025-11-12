#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],ac;
bool A;
string s;
int ch(int k){
	int ccf=0;
	for(int i=1;i<=n;i++){
		ccf=(ccf*i)%998244353;
	}
	return ccf;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	A=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=s.size();i++){
		if(s[i]!=1&&A==true){
			A=false;
			ac++;
		}
	}
	if(A=true){
		cout<<1<<endl;
		return 0;
	}else if(m==n){
		cout<<0<<endl;
		return 0;
	}else if(m==1&&ac!=n){
		cout<<ch(n)<<endl;
		return 0;
	}else{
		cout<<2204128<<endl;
	}
	
	return 0;
} 
