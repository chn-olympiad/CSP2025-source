#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	LL n,k;
	cin>>n>>k;
	LL a[n+1];
	LL sr=0,ans=0;
	for(LL i=0,j=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			j=i+1;
		}else{
			if(i==j){
				sr=a[j];
			}else{
				for(LL l=j;l<i;l++){
					for(LL r=l+1;r<=i;r++){
						sr=sr^a[r];
						if(sr==k){
							ans++;
							j=r+1;
							l=r;
							break;
						}
					}
					sr=a[l+1];
				}
				sr=a[j];
			}
		}
	}
	cout<<ans;
	return 0;
}
