#include<bits/stdc++.h>
#define N 500005
#define M 2000005
using namespace std;
int a[N],pre[N],f[N],maxn[M];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	pre[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=0;i<M;i++)maxn[i]=-1;
	maxn[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(maxn[(pre[i]^k)]!=-1)f[i]=max(f[i],maxn[(pre[i]^k)]+1);
		maxn[pre[i]]=max(maxn[pre[i]],f[i]);
	}
	cout<<f[n];
	fclose(stdin);
	fclose(stdout);
	return 0;
} 