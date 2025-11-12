#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[210000];
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=n-i;j++){
			int cnt=a[j];
			for(int u=j+1;u<j+i;u++){
				cnt=(cnt^a[u]);
			}
			if(cnt==k){
				cout<<i;
				return 0;
			}
		}
	}
	cout<<1;
	return 0;
}
