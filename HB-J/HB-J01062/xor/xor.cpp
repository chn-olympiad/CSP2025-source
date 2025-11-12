#include<bits/stdc++.h>
using namespace std;
int a[500050];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) cnt1++;
		else if(a[i]==0) cnt0++;
	}
	if(cnt1==n){
		cout<<n/2;
	}
	else if(cnt1+cnt0==n){
		if(k==1){
			cout<<cnt1;
		}else{
			int ans=cnt0;
			for(int i=1;i<n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
	}
	
	return 0;
}
