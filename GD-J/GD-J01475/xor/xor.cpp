#include<bits/stdc++.h>
using namespace std;
int n,k,b[500010],a[500010],f[500010],d[2000010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	memset(d,-1,sizeof(d));
	d[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(d[b[i]^k]+1,f[i-1]);
		d[b[i]]=max(d[b[i]],f[i]);
	}
	cout<<f[n];
	return 0;
}
