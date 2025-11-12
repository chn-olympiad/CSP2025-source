#include<bits/stdc++.h>
using namespace std;

int n,k,a[500005],qzh[500005],tot=0,dp[500005];
int son[2][5000005],tree[5000005];

void add(int x,int y){
	int now=0;
	for(int i=19;i>=0;i--){
		int p=x>>i&1;
		if(son[p][now]==0)
			son[p][now]=++tot;
		now=son[p][now];
	}
	tree[now]=y;
	return;
}

int find(int x){
	int now=0;
	for(int i=19;i>=0;i--){
		int p=x>>i&1;
		int q=k>>i&1;
		if(q==1)
			p=1-p;
		if(son[p][now]==0)
			return -1;
		now=son[p][now];
	}
	return tree[now];
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	add(0,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		qzh[i]=qzh[i-1]^a[i];
		if(find(qzh[i])!=-1)
			dp[i]=dp[find(qzh[i])]+1;
		dp[i]=max(dp[i-1],dp[i]);
		add(qzh[i],i);	
	}
	cout<<dp[n];
	return 0;
} 
