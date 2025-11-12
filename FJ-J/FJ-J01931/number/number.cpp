#include<bits/stdc++.h>
using namespace std;
string a;
int x[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	cin>>a;
	int n=a.size();
	for(int i=0;i<n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			int g=a[i]-'0';
			x[g]++;	
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<x[i];j++){
			cout<<i;
		}
	}
	return 0;
}
