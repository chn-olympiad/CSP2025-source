#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],r,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		r=l;
		int xnum=0;
		while(r<=n){
			xnum^=a[r];
			if(xnum==k){
				l=r;
				ans++;
				break;
			}
			r++;
		}
	}
	cout<<ans;
	return 0;
}
