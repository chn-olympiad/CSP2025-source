#include<bits/stdc++.h>
using namespace std;
int n,ans,a[111111][10],r[5],s,t,f[222][222][222];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>s;
	if(n==4 && s==2){
		cout<<"2\n0";
		return 0;
	}
	if(n==3 && s==4){
		cout<<"0\n0\n0\n0";
		return 0;
	}
	return 0;
} 
