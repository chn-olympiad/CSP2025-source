#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int n,a[500010];
long long k;
int x_or(int asd,int b){
	int ans;
	for(int ii =asd;ii<=b;ii++){
		int y=a[ii];
		ans=ans ^ y;
	}
	return ans;
}
int main(){
	//std::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r","stdin");
	freopen("xor.out","w","stdout");
	cin>>n>>k;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	int fds=0;
	for(int i =1;i<=n;i++){
		for(int j =i;j<=n;j++){
			if(x_or(i,j)==k); 
		}
	}
	cout<<fds;
}
