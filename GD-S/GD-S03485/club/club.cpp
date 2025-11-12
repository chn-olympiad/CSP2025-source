#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t;
int n;
struct node{
	int x,y,z;
}a[N];
bool cmp1(node x,node y){
	if(x.x!=y.x)return x.x>y.x;
	if(x.y!=y.y)return x.y>y.y;
	return x.z>y.z;
}bool cmp2(node x,node y){
	return abs(x.x-x.y)>abs(y.x-y.y);
}
int dp[N][15][15][15],cnt1,cnt2,cnt3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		int sz=0;
		for(register int i=1;i<=n;++i)cin>>a[i].x>>a[i].y>>a[i].z,sz+=a[i].z;
		int res=0;
		if(n==1e5){
			cnt1=cnt2=cnt3=0;
			if(sz==0){
				sort(a+1,a+n+1,cmp2);
			}
			else sort(a+1,a+n+1,cmp1);
			for(register int i=1;i<=n;++i){
				int x=max(max(a[i].x,a[i].y),a[i].z),y=min(max(a[i].x,a[i].y),a[i].z),z=min(min(a[i].x,a[i].y),a[i].z);
				if(x==a[i].x){
					if(cnt1<(n>>1)){
						cnt1++;
						res+=a[i].x;		
					}else{
						if(y==a[i].y&&cnt2<(n>>1)){
							cnt2++;
							res+=a[i].y;
						}else{
							cnt3++;
							res+=a[i].z;
						}
					}
				}else if(x==a[i].y){
					if(cnt2<(n>>1)){
						cnt2++;
						res+=a[i].y;
					}else{
						if(y==a[i].x&&cnt1<(n>>1)){
							cnt1++;
							res+=a[i].x;
						}else{
							cnt3++;
							res+=a[i].z;
						}
					}
				}else{
					if(cnt3<(n>>1)){
						cnt3++;
						res+=a[i].z;
					}else{
						if(z==a[i].x&&cnt1<(n>>1)){
							cnt1++;
							res+=a[i].x;
						}else{
							cnt2++;
							res+=a[i].y;
						}
					}
				}
			}cout<<res<<'\n';
			continue;
		}		memset(dp,0,sizeof dp);
		for(register int i=1;i<=n;++i){
			for(register int j=0;j<=n;++j){
				for(register int k=0;k<=n-j;++k){
					int l=i-j-k;
					//if(l>(n>>1)+1||l<0)continue;
					int tmp=-1,id=0;
					if(j!=0)tmp=max(tmp,dp[i-1][j-1][k][l]+a[i].x);
					if(k!=0)tmp=max(tmp,dp[i-1][j][k-1][l]+a[i].y);
					if(l!=0)tmp=max(tmp,dp[i-1][j][k][l-1]+a[i].z);
					dp[i][j][k][l]=tmp;
				//	cout<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<tmp<<" "<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<" "<<dp[i][j][k][l]<<endl;
				}
			}	
		}
			for(register int j=0;j<=(n>>1);++j){
				for(register int k=0;k<=(n>>1);++k){
					int l=n-j-k;
					if(l>(n>>1))continue;
					res=max(res,dp[n][j][k][l]);
				}
			}cout<<res<<'\n';
	}
	return 0;
}
