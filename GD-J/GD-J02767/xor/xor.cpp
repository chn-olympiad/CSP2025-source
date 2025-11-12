#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],b[1501][1501],ans;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			b[i][j]=a[i];
			for(int l=i+1; l<=j; l++) {
				b[i][j]^=a[l];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[i][j]==k){
				ans++;
				i=j;
				break;
			} 
		}
	}
	cout<<ans;
}
