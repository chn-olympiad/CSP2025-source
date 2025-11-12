#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			l=0;
			ans++;
			continue;
		}
		l^=a[i];
		if(l==k){
			l=0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
