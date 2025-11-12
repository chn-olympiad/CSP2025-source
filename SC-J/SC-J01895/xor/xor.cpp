#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[500010],ans=0,s=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	if(k!=0&&k!=1) cout<<s/k;
	else {
		for(int i=1;i<=n;i++){
			if(a[i]==k)ans++;
		}
		cout<<ans;
	}
	
}