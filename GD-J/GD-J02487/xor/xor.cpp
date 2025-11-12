#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <bits/stdc++.h>
using namespace std;

long long n,k,ans;
int a[500010];
int vis[500010];

bool check(int p,int q){
	if(vis[p]) return false;
	int an = a[p];
	vis[p] = true;
	for(int i = p+1;i <= q;i++){
		if(vis[i]) return false;
		an = an^a[i];
		vis[i] = true;
	}
	if(an != k){
		for(int i = p;i <= q;i++) vis[i] = false;
	}
	return (an == k);
}

int main(){
	cin>>n>>k;
	for(int i = 0;i < n;i++) cin>>a[i];
	for(int i = 0;i < n;i++){
		for(int j =i;j < n;j++){
			if(check(i,j)){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
	
}
