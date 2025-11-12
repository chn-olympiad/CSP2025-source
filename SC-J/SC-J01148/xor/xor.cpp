#include<bits/stdc++.h>
using namespace std;
int ans,s,iff,n,k,cinzz,a[500002];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	k=k&1;
	for(int i=1;i<=n;i++){
		cin>>cinzz;
		a[i]=cinzz&1;
		s+=a[i];
		if(i>=2&&a[i-1]!=a[i]){
			iff=1;
		}
	}
	
	if(iff==0){
		cout<<n/2;
		return 0;
	}
	if(k==1){
		cout<<s;
	}
	else{
		for(int i=1;i<n;i++){
			if(a[i]==a[i+1]&&a[i]==1){
				ans++;
				i++;
			}
		}
		cout<<ans+n-s;
	}
	return 0;
}