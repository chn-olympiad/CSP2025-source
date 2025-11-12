#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=(1<<20)+5;
int n,k,a[N],b[N],f[N],g[N];
vector<int>ve[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);

	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>a[i];
	ve[0].push_back(0);
	for(int i=1;i<=n;++i) b[i]=b[i-1]^a[i],ve[b[i]].push_back(i);
	for(int i=1;i<=n;++i){
		int kk=k^b[i];
		for(int v:ve[kk]){
			if(v>i) break;
			f[i]=max(f[i],g[v]+1);
		}
		g[i]=max(g[i-1],f[i]);
	}
	cout<<g[n];
}
