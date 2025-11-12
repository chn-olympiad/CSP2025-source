#include<bits/stdc++.h>
using namespace std;
int a[10];
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	string x;
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			a[x[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int ii=0;ii<a[i];ii++){
			cout<<i;
		}
	}
}

