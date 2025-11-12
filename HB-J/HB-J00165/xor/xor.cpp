#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200007];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)ans++;
			if(a[i]==1&&a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans;
	}
	else if(k==1){
		long long ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)ans++;
		}
		cout<<ans;
	}
	return 0;
}

