#include<bits/stdc++.h>
#define int long long 
#define lc (k<<1)
#define rc ((k<<1)|1)
#define mid ((l+r)>>1)
#define N 10005
using namespace std;
int n,v,ms[N<<4],a[N],b[N][N],dp[N][N];
void bud(int k, int l,int r){
	if(l==r){
		ms[k]=a[l];
		return ;
	}
	bud(lc,l,mid);
	bud(rc,mid+1,r);
	ms[k]=(ms[lc]^ms[rc]);
}
int quy(int k,int l,int r,int x,int y){
	if(x<=l&&r<=y){
		return ms[k];
	}
	int res=0;
	if(x<=mid){
		res^=quy(lc,l,mid,x,y);
	}
	if(y>mid){
		res^=quy(rc,mid+1,r,x,y);
	}
	return res;
}
signed main(){
	//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>v;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bud(1,1,n);
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int res=quy(1,1,n,l,r);
			b[l][r]=res;
		}
	}
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			if(b[l][r]==v){
				dp[l][r]=max(dp[l][r],(int)1);
			}else{
				dp[l][r]=max(dp[l][r],max(dp[l-1][r],dp[l][r-1]));
			}
			for(int k=l+1;k<r;k++){
				dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
			}
			
		}
	}
	cout<<dp[1][n];
	fclose(stdin);
	fclose(stdout);
	return 0;
}