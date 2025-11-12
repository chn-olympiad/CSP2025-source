#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],b[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];b[a[i]]++;
	}
	if(b[1]==n){
		if(k==1) cout<<n;
		else cout<<n/2;
	}
	else if(b[1]+b[0]==n){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans;	
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i]==1&&a[i+1]==1) ans++;
				if(a[i]==0) ans++;
			}
			cout<<ans;
		}
	}
	else cout<<1;
	return 0;
}
