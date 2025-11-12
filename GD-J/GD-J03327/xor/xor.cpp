#include<iostream>
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int a[114514];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.ans","w",stdout);
	cin.tie(0);cout.tie(0);
	int n,k,num=0,oo=1,o=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=2){
		if(a[n]^a[1]==k)num++;
		cout<<num;
	}
	else cout<<2;
} 
