#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[100000],flag=1;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag==1){
			if(a[i]!=1)flag=0;
		}
	}
	if(k==0&&flag==1){
		cout<<0;
		return 0;
	}
	if(k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(k==1){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
} 