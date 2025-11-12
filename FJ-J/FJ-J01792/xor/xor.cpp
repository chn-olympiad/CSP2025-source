#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int sum[N];
int f[N];
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
		sum[i]=sum[i-1]^a[i];
	}
	sum[1]=a[1];
	f[0]=0;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		for(int l=1;l<=i;l++){
			int w=sum[i]^sum[l-1];
			if(l-1==0)w=sum[i];
			if(w==k){
				//cout<<i-l+1<<' '<<i<<'\n';
				f[i]=max(f[i],f[l-1]+1);
			}
		}
	}
	cout<<f[n]<<'\n';
	return 0;
}
