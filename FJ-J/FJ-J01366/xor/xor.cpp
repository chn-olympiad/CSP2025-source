#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10,K=2e6+10;
int n,k,a[N],d[K],f[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		a[i]^=a[i-1];}
	for(int i=0;i<=(1<<20);i++)
		d[i]=-1e9-10;
	d[k]=0;
	for(int i=1;i<=n;i++){
		f[i]=max(f[i-1],d[a[i]]+1);
		d[a[i]^k]=f[i];}
	cout<<f[n]<<endl;
	return 0;
} 
