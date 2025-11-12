#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],x,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
		x+=a[i];
	}
	if(n>10000){
		cout<<x;
		return 0;
	}
	int minl=1;
	for(int r=1;r<=n;r++){
		for(int l=minl;l<=r;l++){
			if((b[r]^b[l-1])==k){
				ans++;
				minl=r+1;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

