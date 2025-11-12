#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e6+5;
int n,k;
int a[N],sum[N],p[M],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int r=0;
	memset(p,-0x3f,sizeof p);
	p[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),sum[i]=sum[i-1]^a[i];
		if(p[sum[i]^k]>=r) ans++,r=i;
		p[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}