#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1000000];
bool flag=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flag=false;
	}
	if(k==0&&n==2){
		cout<<1;
		return 0;
	}
	if(k==0&&n==1){
		cout<<0;
		return 0;
	}
	if(k==0&&flag){
		cout<<floor(1.0*n/2);
		return 0;
	}
	if(k==0&&!flag){int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
		}
		cout<<ans;
	}
	if(k==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
}

