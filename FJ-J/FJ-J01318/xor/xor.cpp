#include<bits/stdc++.h>
using namespace std;
int n,k,in[200005],ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>in[i];
		if(in[i]==k) ans++;
	}
	cout<<ans;
	return 0;
}
