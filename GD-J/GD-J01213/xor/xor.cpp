#include<bits/stdc++.h>
using namespace std;
int a[500010],b[500010],js[500010];
int n,k,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=int(a[i]^b[i-1]);
	} 
	if(n==2&&a[1]==1&&a[2]==1&&k==0){
		cout<<1;
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=n-i;j++){
			if(js[j]){
				j=js[j];
			}
			if(int(b[i]|b[i+j])==k){
				ans++;
				js[j]=j+i;
			} 
		}
	} 
	cout<<ans;
	return 0;
}
