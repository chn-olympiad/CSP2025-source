#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
const int N=5e5+10,M=(1<<20)+5;
const int inf=1e7;
ll a[N],k,sxo[N];
int n,f[N],pre[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],
		sxo[i]=sxo[i-1]^a[i];
	for(int i=0;i<=n;i++)
		f[i]=-inf,pre[i]=-1;
	pre[0]=0;
	f[0]=0;
	for(int i=1;i<=n;i++){
		ll rxor=sxo[i]^k;
		f[i]=f[i-1];
		if(pre[rxor]!=-1)
			f[i]=max(f[i],f[pre[rxor]]+1);
		pre[sxo[i]]=i;
	}
	cout<<f[n];
	return 0;
}
