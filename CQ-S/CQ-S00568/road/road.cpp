#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,K,f[1001][1001];
struct node{
	ll v,num[1001];
}e[1001];
ll dp[1001][1001],minn=7777777777;
bool book[1001][1001][11];
void check(int noww,int ac,int L){
	if(L==n&&ac<minn){
		minn=ac;
		return;
	}
	for(ll i=noww+1;i<=n;i++)check(i,ac+dp[noww][i],L+1);
}
int main()
{
	memset(dp,0x7f,sizeof(dp));
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&K);
	ll x,y,z;
	for(ll i=1;i<=m;i++){
		scanf("%lld%lld%lld",&x,&y,&z);
		f[x][y]=z;
		f[y][x]=z;
	}
	for(ll i=1;i<=K;i++){
		scanf("%lld",e[i].v);
		for(int j=1;j<=n;j++)scanf("%lld",e[i].num[j]);
	}
	dp[0][0]=0;
	for(ll i=1;i<=n;i++){
		for(ll k=i+1;k<=n;k++){
			for(ll j=i+1;j<=n;j++){
				ll cnt=0;
				if(f[i][j]){
					for(ll l=1;l<=K;l++){
						if(!book[i][j][l]){
							if(e[l].num[i]+e[l].num[j]+e[l].v<=dp[i][j]){
								dp[i][j]=e[l].num[i]+e[l].num[j]+e[l].v;
								cnt=l;
							}
						}
						else if(e[l].num[i]+e[l].num[j]<dp[i][j])dp[i][j]=e[l].num[i]+e[l].num[j];
					}
					if(cnt)book[i][j][cnt]=1;
					dp[i][j]=min(min(f[i][j],dp[i][j]),dp[i][k]+dp[k][j]);
				}
				if(f[k][j]){
					dp[i][j]=min(dp[i][j],dp[i][k]+f[k][j]);
					for(int l=1;l<=K;l++){
						if(!book[k][j][l]){
							if(e[l].num[k]+e[l].num[j]+e[l].v+dp[i][k]<=dp[i][j]){
								dp[i][j]=e[l].num[k]+e[l].num[j]+e[l].v+dp[i][k];
								cnt=l;
							}
						}
						else if(e[l].num[k]+e[l].num[j]+dp[i][k]<dp[i][j])dp[i][j]=e[l].num[k]+e[l].num[j]+dp[i][k];
					}
					if(cnt)book[i][j][cnt]=1;
				}
				if(f[i][k]){
					dp[i][j]=min(dp[i][j],f[i][k]+dp[k][j]);
					for(int l=1;l<=K;l++){
						if(!book[i][k][l]){
							if(e[l].num[i]+e[l].num[k]+e[l].v+dp[k][j]<=dp[i][j]){
								dp[i][j]=e[l].num[i]+e[l].num[k]+e[l].v+dp[k][j];
								cnt=l;
							}
						}
						else if(e[l].num[i]+e[l].num[k]+dp[k][j]<dp[i][j])dp[i][j]=e[l].num[i]+e[l].num[k]+dp[k][j];
					}
					if(cnt)book[i][j][cnt]=1;
				}
			}
		}
	}
	check(1,0,0);
	cout<<minn;
	return 0;
}
