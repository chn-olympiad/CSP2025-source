#include <bits/stdc++.h>
using namespace std;
long long int n,k,la,lah,ans;
int a[9999999];
int xo[9999999];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
    	xo[i]=(a[i]^xo[i-1]);
	}
	for(int i=1;i<=n;i++){
		la=lah-1;
		while(la<=i){
			if(i==la){
				if(a[i]==k){
					ans++;
					lah=i+1;
					break;
				}	
			}
			else if((xo[i]^xo[la])==k){
				ans++;
				lah=i+1;
				break;
			}
			la++;
		}
	}
	cout<<ans;
	
	return 0;
}
