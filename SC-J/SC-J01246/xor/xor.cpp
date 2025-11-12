//xor
#include<bits/stdc++.h>
using namespace std;

const int N=2e6+5;

int n,k;
int a[N],t[N],f[N];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		a[i]^=a[i-1];
	}
	for(int i=1;i<(1<<20);++i) t[i]=-1;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];
		if(t[a[i]^k]!=-1) f[i]=max(f[i],f[t[a[i]^k]]+1);
		t[a[i]]=i;
	}
	cout<<f[n];
	return 0;
}