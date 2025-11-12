#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5,inf=1e18;
int T,n;
int a[N][5];
int b[N],ty[N],ex[N];
ll dp[205][205];
bool cmp1(int x,int y){
	return a[x][1]-a[x][2]>a[y][1]-a[y][2];
}
bool cmp2(int x,int y){
	return ex[x]>ex[y];
}
void solve0(){//±©Á¦ 
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			dp[i][j]=-inf;
		}
	}
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>=0;j--){
			for(int k=n/2;k>=0;k--){
				dp[j][k]=max(dp[j][k],dp[j][k]+a[i][3]);
				if(j>=1)dp[j][k]=max(dp[j][k],dp[j-1][k]+a[i][1]);
				if(k>=1)dp[j][k]=max(dp[j][k],dp[j][k-1]+a[i][2]);
			}
		}
	}
	ll ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			if(n-i-j>n/2)continue;
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%lld\n",ans);
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			scanf("%d",&a[i][j]);
		}
	}
	if(n<=200){
		solve0();
		return ;
	}
	for(int i=1;i<=n;i++)b[i]=i;
	sort(b+1,b+1+n,cmp1);
	for(int i=1;i<=n;i++){
		if(i<=n/2)ty[b[i]]=1;
		else ty[b[i]]=2;
	}
	for(int i=1;i<=n;i++){
		b[i]=i,ex[i]=a[i][3]-a[i][ty[i]];
	}
	sort(b+1,b+1+n,cmp2);
	for(int i=1;i<=n/2&&ex[b[i]]>0;i++){
		ty[b[i]]=3;
	}
	int ok=n/2,cnt=0;
	for(int i=1;i<=n;i++){
		if(ty[i]==2)b[++cnt]=i;
		if(ty[i]==1)ok--;
	}
	sort(b+1,b+1+cnt,cmp1);
	for(int i=1;i<=cnt&&ok;i++){
		if(a[b[i]][1]<a[b[i]][2])break;
		ty[b[i]]=1,ok--;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)ans+=a[i][ty[i]];
	printf("%lld\n",ans);
}
int main(){
	freopen("club.in","r",stdin);
//	freopen("in.txt","r",stdin);
	freopen("club.out","w",stdout);
//	solve();
//	return 0;
	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}/*
6
8 2 3 
3 1 0 
8 7 8 
3 6 7 
6 5 3 
7 8 1 
*/
