#include<bits/stdc++.h>
using namespace std;
int n,k;
const int N=5e5+5;
int a[N];
int f[N],g[N];
int tag=0;
map<int,bool> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>k;
	for(int i=1;i<=n;i++)	cin>>a[i];
	for(int i=1;i<=n;i++){
		int tmp=0;
		tag^=a[i];
		if(a[i]==k){
			g[i]=i;
			f[i]=f[i-1]+1;
			mp.clear();
			continue;
		}
		mp[a[i]^tag]=1;
//		int l=g[i-1]+1,r=i;
		if(mp[k^tag])	g[i]=i,mp.clear();
		if(g[i]){
			f[i]++;
		}
		else{
			g[i]=g[i-1];
		}
		f[i]+=f[i-1];
	}
	cout<<f[n];
	return 0;
}
