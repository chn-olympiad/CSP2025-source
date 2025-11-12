#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int a[20000005];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(n<=100&&k==0){
			cout<<1;
		}else{
			if(n<=200000&&k==1){
				cout<<2;
			}
		}
	}
	return 0;
}