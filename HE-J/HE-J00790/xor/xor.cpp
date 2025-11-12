#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],ans;
int num1,num0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]==1) num1++;
		if(a[i]==0) num0++;
	}
	if(num1==n){
		if(n%2==0) ans=n;
		else ans=0;
	} else if(num1+num0==n){
		if(num1%2==k) ans=n;
		else{
			int zca=1,z=0,dca=n,d=0;
			while(a[zca]==0){
				zca++, z++;
			}
			while(a[dca]==0){
				dca--, d++;
			}
			ans=n-min(z+1,d+1);
		}
	}
	cout << ans;
	return 0;
} 
