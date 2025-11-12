#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],c[N],f[N],mp[(1<<21)];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=c[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		mp[c[i-1]]=i;
		int j=mp[c[i]^k];
		if(j) f[i]=max(f[i],f[j-1]+1);
	}
	cout<<f[n];
	return 0;
}
