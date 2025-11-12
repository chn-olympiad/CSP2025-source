#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],t[260];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<256)t[a[i]]++;
	}
	if(!k){
		int ans=t[0];
		for(int i=1;i<256;i++)ans+=t[i]/2;
		cout<<ans;
		return 0;
	}
	if(k<2){
		cout<<max(t[1],t[0]);
		return 0;
	}
	cout<<n/2;
	return 0;
}