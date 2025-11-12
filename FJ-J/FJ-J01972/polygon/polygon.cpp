#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int a[N];
bool check(int l,int r){
	int ct=0,maxm=-1;
	for(int i=l;i<=r;i++){
		ct+=a[i];
		maxm=max(maxm,a[i]);
	}
	return ct>2*maxm;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,ct=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=ct;i++){
		for(int j=1;j+i-1<=ct;j++){
			if(check(j,j+i-1)){
				ct=(ct+1)%998244353;
			}
		}
	}
	cout<<ct%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
