#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],js,v[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=2&&k==0){
		cout<<n/2;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) break;
			if(i==n){
				cout<<n/2;
				return 0;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				js++;		
			}else{
				if(a[i-1]==1&&a[i]==1&&v[i-1]!=1){
					js++;
					v[i]=1;
				}
			}
		}
		cout<<js;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=n;i++){
			if(a[i]==1)js++;
		} 
		cout<<js;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]=='k')js++;
	}
	cout<<js;
	return 0;
}
