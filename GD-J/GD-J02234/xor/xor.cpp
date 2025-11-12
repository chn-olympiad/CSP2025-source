#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],s[N],c[N*4],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	memset(c,-1,sizeof(c));c[0]=0;
	for(int i=1; i<=n; i++)cin>>a[i],s[i]=(s[i-1]^a[i]);
	for(int i=1; i<=n; i++){
		f[i]=max(f[i-1],c[s[i]^k]+1);
		c[s[i]]=max(c[s[i]],f[i]);
	}
	cout<<f[n];
	return 0;
} 
