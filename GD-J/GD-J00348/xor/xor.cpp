#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,k;
int a[N+5];
int pre[N+5];
int f[N+5];
unordered_map<int,int> las;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		pre[i]=pre[i-1]^a[i];
	}
	las[0]=0;
	f[0]=0;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1];
		if(las.count(pre[i]^k))
			f[i]=max(f[i],f[las[pre[i]^k]]+1);
		las[pre[i]]=i;
	}
	printf("%d",f[n]);
	return 0;
}

