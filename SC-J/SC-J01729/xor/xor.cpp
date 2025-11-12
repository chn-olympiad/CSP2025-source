#include<bits/stdc++.h>
using namespace std;
int n,k,a[5000005]={0},xorList[5000005]={0},l,r,vis[5000005]={0},nx,ans=1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k>>a[0];
	xorList[0]=a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
		xorList[i]=xorList[i-1]^a[i];
	}
	while(l<=n&&r<=n){
		while(vis[r++]){
			l=r;
		}
		if(l>n||r>n)break;
		nx=xorList[l]^xorList[r];
		if(nx==k){
			ans++;
			for(int i=l;i<=r;i++){
				vis[i]=1;
			}
		}
		r++;
	} 
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
    return 0;
}
