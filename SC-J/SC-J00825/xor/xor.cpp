#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],b[500005],f[500005],g[1050000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	f[0]=-1;
	for(int i=1;i<=n;i++){
		g[b[i]]=i;
		if(b[i]==k){
			f[i]=max(f[i-1],1);
		}else{
			f[i]=max(f[i-1],f[g[b[i]^k]]+1);
		}
	}
	cout<<f[n];
	return 0;
}
