#include<bits/stdc++.h>
#define N 500100
using namespace std;
int n,k,a[N],f[N],pos[1<<20];
int main(){
	freopen("xor.in","r",stdin),freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>n>>k; for(int i=1;i<=n;i++) cin>>a[i];
	memset(pos,-1,sizeof(pos)); f[0]=0,pos[0]=0;
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1],f[i]=f[i-1];
		if(pos[a[i]^k]!=-1) f[i]=max(f[i],f[pos[a[i]^k]]+1); pos[a[i]]=i;
	} return cout<<f[n]<<endl,0;
}