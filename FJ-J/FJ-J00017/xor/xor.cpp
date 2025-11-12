#include<bits/stdc++.h>
using namespace std;
int n,k,a[1005],xr[1005][1005],ans;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		xr[i][i]=a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n-k+1;i++){
			xr[i][i+k]=xr[i+1][i+k] xor a[i];
		}
	}
	int y=1;
	for(int r=1;r<=n;r++)
		for(int l=r;l>=y;l--)
			if(xr[l][r]==k){
				ans++;
				y=r+1;
				break;
			}
	cout<<ans;
	return 0; 
}
