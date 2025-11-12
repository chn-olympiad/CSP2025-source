#include<bits/stdc++.h>
using namespace std;
int n,k,ans=0;
int a[500010];
int xo[500010];
int f[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xo[i]=a[i]^xo[i-1];
	}
	int l=0;
	for(int i=1;i<=n;i++){
		for(int j=l;j<i;j++){
			if((xo[i]^xo[j])==k){
				ans++,l=i;
				break; 
			}
		}
	}
	cout<<ans;
	return 0;
}
