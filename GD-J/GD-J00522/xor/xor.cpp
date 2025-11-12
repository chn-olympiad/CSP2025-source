#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],sum[N],m;
struct node{
	int l,r;
}b[2*N],kk;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=(sum[i-1]^a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((sum[i-1]^sum[j])==k){
				kk.l=i; kk.r=j;
				b[++m]=kk;
				break;
			}
		}
	}
	int R=b[1].r,ans=1;
	for(int i=2;i<=m;i++){
		if(b[i].l>R) ans++,R=b[i].r;
		else R=min(R,b[i].r);
	}
	cout<<ans;
	return 0;
}
