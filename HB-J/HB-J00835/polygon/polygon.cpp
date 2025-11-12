#include <bits/stdc++.h>
using namespace std;

const int N=5e3+7;

const int mod = 998244353;

int a[N];

int n;

int suf[N];

int cmp(int a,int b){
	return a<b;
}

int main(){
	cin>>n;
	
	
	for(int i=0;i<n;++i){
		cin>>a[i];
	}
	
	
	
	sort(a,a+n,cmp);


	cout<<0;
	
}
