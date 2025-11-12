#include <bits/stdc++.h>
using namespace std;
const int N = 1.5e6 + 7;
int n, x, i, xors, k;
int c[N], t[N], a[N], maxf[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++){
		cin>>x;
		xors^=x;
		a[i]=xors;
		c[i]=t[i]=-1;
	}
	for(i=1;i<=n;i++){
		c[i]=t[a[i]^k];
		t[a[i]]=i;
	}
	for(i=1;i<=n;i++){
		maxf[i]=maxf[i-1];
		if(c[i]!=-1)maxf[i]=max(maxf[i], maxf[c[i]]+1);
	}
	cout<<maxf[n]<<"\n";
	return 0;
}

