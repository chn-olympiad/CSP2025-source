#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005],f[500005],sum[500005],bj[1050000],qy[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(bj,0x3f,sizeof(bj));
	bj[0]=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		qy[i]=bj[sum[i]^k];
		bj[sum[i]]=i;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(qy[i]!=0x3f3f3f3f) f[i]=max(f[i],f[qy[i]]+1);
//		cout<<f[i]<<' ';
	}
	cout<<f[n];
	return 0;
} 