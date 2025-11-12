#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500005
bool f;
int n,k,a[N];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		if(a[i]!=1)f=1;
	}
	if(f==false){
		if(k==1)cout<<n;
		else cout<<n/2;
		return 0;
	}
	return 0;
}
