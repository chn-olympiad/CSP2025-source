#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==2){
		if((a[1]^a[2])==k){
			cout<<2;
			return 0;
		}
		if((a[1]^a[1])==k&&(a[1]^a[1])==k){
			cout<<1;
			return 0;
		}
	}
	return 0;
}