#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],f,cnt,dp[500005],nxt1,nxt2,pre[500005];
struct node{
	int l,r;
}q[500005];
bool cmp(node x,node y){
	if(x.r!=y.r)return x.r<y.r;
	else return x.l<y.l;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			if(a[i]==0)f=1;
			else f=2;
		}
	}
	a[0]=-1;
	if(f==0){
		cout<<n/2<<endl;
		return 0;
	}
	if(f==1){
		if(k==0){
			for(int i=1;i<=n;i++){
				nxt1=nxt2=-1;
				if(a[i]==0)nxt1=dp[i-1]+1;
				if(a[i]==a[i-1])nxt2=dp[i-2]+1;
				dp[i]=max(max(nxt1,nxt2),dp[i-1]);
			}
			cout<<dp[n]<<endl;
		}
		if(k==1){
			for(int i=1;i<=n;i++){
				nxt1=nxt2=-1;
				if(a[i]==1)nxt1=dp[i-1]+1;
				if(a[i]!=a[i-1])nxt2=dp[i-2]+1;
				dp[i]=max(max(nxt1,nxt2),dp[i-1]);
			}
			cout<<dp[n]<<endl;
		}
		return 0;
	}
	for(int i=1;i<=n;i++)q[i].l=i,q[i].r=2e9;
	pre[1]=a[1];
	for(int i=2;i<=n;i++)pre[i]=pre[i-1]^a[i];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if((pre[j]^pre[i-1])==k){
				q[i].r=j;
				break;
			}
		}
	}
	sort(q+1,q+n+1,cmp);
	for(int i=1;i<=n;i++)dp[q[i].r]=max(dp[q[i].r],dp[q[i].l-1]+1);
	for(int i=1;i<=n;i++)dp[i]=max(dp[i],dp[i-1]);
	cout<<dp[n]<<endl;
	return 0;
}
