#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n;
int a[5010];
long long ans;
bool polygon(int as,int bs){
	int h=0;
	int m=0;
	for(int ii=as;ii<=bs;ii++){
		h+=a[ii];
		m=max(m,a[ii]);
	}
	return h>m;
}
int main(){
	//std::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	cin>>n;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	for(int i =1;i<=n-2;i++){
		for(int j =i+2;j<=n;j++){
			if(polygon(i,j)) ans=ans+1;ans=ans%998244353;
		}
	}
	cout<<ans;
}
