#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
int n,a[5005]={};
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int sum=0,he=0;
void dfs(int k){
	if(he>a[0]*2) {
		sum+=1;
	}
	for (int i=k;i<n;i++){
		if(he<=a[0]*2){
			he+=a[i];
			dfs(k+1);
			he-=a[i];
		}
	}
} 

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	dfs(0);
	cout<<sum%998244353;
}
