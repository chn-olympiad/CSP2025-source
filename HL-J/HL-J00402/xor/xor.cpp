#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int ans=0;
	int n,k;
	cin >> n >> k;
	for(int i = 1;i<=n;i++){
		cin >> b[i];
		a[i]=b[i]^a[i-1];
	}
	if(k!=0){
		int l=0,r=0;
		for(l = 0;l<=n;l=r){
			for(r = l;r<=n;r++){
				if((a[r]^a[l])==k){
					ans++;
					//cout << l << " " << r  <<endl;
					break;
				}
			}
		}
	}
	if(k==0){
		for(int i = 1;i<=n;i++){
			if(b[i]==0){
				ans++;
			}
		}
	}

	cout << ans;
	return 0;
}
