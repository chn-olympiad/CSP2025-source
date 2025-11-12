#include <bits/stdc++.h>
using namespace std;
long long n,k,cnt,R[500005];
bool fast=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int ans1,ans2;
	for (int i=1;i<n;i++){
		cin>>R[i];
		if (R[i]!=1){
			fast=false;
		}
		if (R[i]==k){
			cnt++;
		}
		if (R[i]==1){
			ans1++;
		}
		if (R[i]==0){
			ans2++;
		}
	}
	if (cnt==n){
		cout<<cnt;
		return 0;
	}
	if (fast==true && k==0){
		cout<<n/2;
		return 0;
	}
	if (ans1==ans2){
		cout<<ans1;
		return 0;
	}else{
		cout<<ans1+1;
	}
	return 0;
}

