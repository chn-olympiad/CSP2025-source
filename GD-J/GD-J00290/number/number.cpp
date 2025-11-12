#include<bits/stdc++.h>
using namespace std;
string x;
int a[1000005];
int n=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			a[++n]=x[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
} 
