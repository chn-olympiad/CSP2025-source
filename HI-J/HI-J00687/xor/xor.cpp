#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k=0) cout<<1;
	else cout<<k;
	return 0;
}

