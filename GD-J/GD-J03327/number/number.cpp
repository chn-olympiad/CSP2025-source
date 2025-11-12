#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a[1145140],k=1;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);cout.tie(0);
	string n;
	cin>>n;
	for(int i=0;i<n.size();i++){
		if(isdigit(n[i])){
			a[k]=n[i]-'0';
			k++;
		}
	}
	if(k<=10000){
	for(int i=1;i<k-1;i++){
		bool f=1;
		for(int j=1;j<k-i+1;j++){
			if(a[j]<a[j+1]){
				swap(a[j],a[j+1]);
				f=0;
			}
		}
		if(f)break;
	}
	for(int i=1;i<=k;i++){
		cout<<a[i];
	}
	return 0;
	}
	sort(a+1,a+k+1);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}
