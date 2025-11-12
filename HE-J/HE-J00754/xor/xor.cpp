#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[200010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool b=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1){
			b=false;
		}
	}
	if(b){
		cout<<n/2;
		return 0;
	}
	int ans=0;
	for(int i=0;i<n;i+=2){
		if(a[i]^a[i+1]==k){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
