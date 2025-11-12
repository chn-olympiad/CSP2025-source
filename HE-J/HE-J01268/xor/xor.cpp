#include <bits/stdc++.h>
using namespace std;

const int N=5e5+5,K=1<<21;
int a[N],s[N],f[N],maxn[K],idx[K];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,sum=0;
	scanf("%d %d",&n,&k);
	memset(idx,-1,sizeof(idx));
	idx[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		s[i]=s[i-1]^a[i];
		if(idx[s[i]]==-1) idx[s[i]]=i;
	} 
	for(int i=1;i<=n;i++){
		int x=s[i]^k;
		if(idx[x]!=-1 && idx[x]<i) f[i]=max(f[i],maxn[x]+1);
		f[i]=max(f[i],f[i-1]);
		maxn[s[i]]=max(maxn[s[i]],f[i]);
	}
	cout<<f[n];
	return 0;
}

