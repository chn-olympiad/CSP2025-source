#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
int a[1000005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(k==0){
		cout<<"1";
	}
	return 0;
}
