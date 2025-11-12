#include<bits/stdc++.h>
using namespace std;
#define reg register
#define int long long
const int N=1e5+10;
const int M=1e4+10;
inline int max(int a,int b){return a>b?a:b; }
inline int min(int a,int b){return a<b?a:b; }
int T,n,cnt1,cnt2,cnt3,ans,m;
struct node{
	int a1,a2,a3;
}a[N];
int f[N];
int dp[M][M];
void dfs(int x,int sum){
	if(x==n+1){
		ans=max(ans,sum);		
		return ;
	}
	if(sum+f[x]<=ans)return ;
	if(cnt1<m){
		cnt1++;
		dfs(x+1,sum+a[x].a1);
		cnt1--;
	}
	if(cnt2<m){
		cnt2++;
		dfs(x+1,sum+a[x].a2);
		cnt2--;
	}
	if(cnt3<m){
		cnt3++;
		dfs(x+1,sum+a[x].a3);
		cnt3--;
	}
}
bool cmp1(node xx,node yy){
	return xx.a1>yy.a1;
}
bool cmp2(node xx,node yy){
	return xx.a2>yy.a2;
}
bool cmp3(node xx,node yy){
	return xx.a3>yy.a3;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--){
		scanf("%lld",&n);
		cnt1=cnt2=cnt3=ans=0;
		int count1=0,count2=0,count3=0;
		for(reg int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a1==0)count1++;
			if(a[i].a2==0)count2++;
			if(a[i].a3==0)count3++;
		}
		m=n/2;
		if(count2==n&&count3==n){
			sort(a+1,a+n+1,cmp1);
			for(reg int i=1;i<=m;i++)
				ans+=a[i].a1;
			printf("%d\n",ans);
			continue;
		}
		if(count1==n&&count3==n){
			sort(a+1,a+n+1,cmp2);
			for(reg int i=1;i<=m;i++)
				ans+=a[i].a2;
			printf("%d\n",ans);
			continue;
		}
		if(count1==n&&count2==n){
			sort(a+1,a+n+1,cmp3);
			for(reg int i=1;i<=m;i++)
				ans+=a[i].a3;
			printf("%d\n",ans);
			continue;
		}
		if(count2!=n&&count3==n){
			for(reg int i=0;i<=m;i++)
				for(reg int j=0;j<=m;j++)
					dp[i][j]=0;	
			for(reg int i=1;i<=n;i++){
				for(reg int j=m;j>=0;j--){
					for(reg int k=m;k>=0;k--){
						if(j>0)dp[j][k]=max(dp[j-1][k]+a[i].a1,dp[j][k]);
						if(k>0)dp[j][k]=max(dp[j][k-1]+a[i].a2,dp[j][k]);
					}
				}
			}
			printf("%lld\n",dp[m][m]);
			continue;
		}
		for(reg int i=n;i>=1;i--){
			f[i]=f[i+1]+max(a[i].a1,max(a[i].a2,a[i].a3));
		}
		dfs(1,0);
		printf("%lld\n",ans);
	}
}


