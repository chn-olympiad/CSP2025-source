#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
long long R[100000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool fast=true;
	cin>>n>>k;	
	for(int i;i<=n;i++){
		 cout<<R[i];
		 fast=true;
		 	return 0;
	}
	cin>>cnt;
		
	if(R[i]!=1){
		ans1++;
		cout<<cnt;
			return 0;
	}
	if(R[i]==0){
		ans2++;
		cout<<cnt;
	}
	if(cnt==n){
		cout<<cnt;
		return 0;
	}
	if(fast=true&&k++0){
		cout<<n/2;
		return 0;
	}
	if(ans1==ans2){
		cout<<ans2;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);	
	return 0;
}
