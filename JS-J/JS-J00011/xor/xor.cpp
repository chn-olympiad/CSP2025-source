#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n,k;
int ans,ct;
int a[N];
bool fl=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]==0) fl=0;
	}
	if(fl){
		cout<<n;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==k) ct++;
		}
	}
	cout<<ct;
	return 0;
}
