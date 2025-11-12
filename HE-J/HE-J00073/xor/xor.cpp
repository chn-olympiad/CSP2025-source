#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,V=2e6;
int n,k,a[N],s[N],lst[V],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i],s[i]=a[i]^s[i-1];
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+(a[i]==k);
		if(s[i]==k) f[i]=max(f[i],1);
		if(lst[k^s[i]]) f[i]=max(f[i],f[lst[k^s[i]]]+1);
		lst[s[i]]=i;
	}
	cout<<f[n];
	return 0;
}
