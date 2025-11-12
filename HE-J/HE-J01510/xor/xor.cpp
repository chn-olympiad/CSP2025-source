#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,s,a[2100000],q[2100000],w[2100000];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n-1;i>=0;i-=2){
		s+=i;
	}
	cout<<s;
	return 0;
}
