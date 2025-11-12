#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[1048580],s[500005],f[500005],mx[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=1048576;i++){
		c[i]=n+1;
	}
	mx[n+1]=-0x7f7f7f7f;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]^a[i];
		int g=s[i]^m;
		f[i]=mx[c[g]]+1;
		c[s[i]]=i;
		mx[i]=max(mx[i-1],f[i]);
	}
	cout<<mx[n];
	return 0;
}