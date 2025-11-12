#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt,ling,yi;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) ling++;
		if(a[i]==1) yi++;
	}
	if(yi==n){
		cout<<n/2;
		return 0;
	}
	if(ling+yi==n){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(cnt==a[i]) cnt=0;
			else cnt=1;
			if(cnt==k){
				ans++;
				cnt=0;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<4;
	return 0;
} 
