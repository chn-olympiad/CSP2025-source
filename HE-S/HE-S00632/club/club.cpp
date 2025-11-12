#include<bits/stdc++.h>
using namespace std;
#define ll long long
void st(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}
const int nm=1e5+10;
int t,n,ans,flag,flag2,sum[4],cnt;
int a[nm][4],dp[205][205][205];
int b[nm],num[4],vis[nm];
int cha[nm],cha2[nm];
typedef pair<int,int> p;
struct node{
	int val,id,gp;
}s[nm];
bool cmp(node x,node y){
	return x.val>y.val;
}
signed main(){
	freopen("club.in","r",stdin);//¼ì²éÎÄ¼þ¼Ð!
	freopen("club.out","w",stdout);
	st();
	cin>>t;
	while(t--){
		cin>>n;
		cnt=sum[2]=sum[3]=flag=flag2=ans=0;
		memset(dp,0,sizeof(dp));
		memset(num,0,sizeof(num));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++) cin>>a[i][j];
			if(a[i][2]||a[i][3]) flag=1;
			if(a[i][3]) flag2=1;
		}
		if(!flag){
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+n+1);
			for(int i=n;i>n/2;i--) ans+=b[i];
			cout<<ans<<'\n';
			continue;
		}
		if(!flag2){
			for(int i=1;i<=n;i++) cha[i]=a[i][2]-a[i][1];
			sort(cha+1,cha+1+n);
			for(int i=1;i<=n;i++) ans+=a[i][1];
			for(int i=n;i>n/2;i--) ans+=cha[i];
			cout<<ans<<'\n';
			continue; 
		}
//		if(n==100000){
//			for(int i=1;i<=n;i++){
//				cha[i]=a[i][2]-a[i][1];
//				cha2[i]=a[i][3]-a[i][1];
//				ans+=a[i][1];
//				s[++cnt]={cha[i],i,2};
//				s[++cnt]={cha2[i],i,3};
//			}
//			sort(s+1,s+cnt+1,cmp);
//			int pos=1;
//			for(int i=1;i<=n/2;i++){
//				int vall=s[pos].val,idd=s[pos].id,gpp=s[pos].gp;
//				if(!vis[idd]&&num[gpp]<n/2){
//					num[gpp]++;
//					ans+=vall;
//					vis[idd]=1;
//				}
//				else i--;
//				pos++;
//			}
//			while(s[pos].val>0){
//				int vall=s[pos].val,idd=s[pos].id,gpp=s[pos].gp;
//				if(!vis[idd]&&num[gpp]<n/2){
//					num[gpp]++;
//					ans+=vall;
//					vis[idd]=1;
//				}
//				pos++;
//				if(pos>cnt) break;
//			}
//			cout<<ans<<'\n';
//			continue;
//		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n/2&&j<=i;j++){
				for(int k=0;k<=n/2&&k+j<=i;k++){
					if(j>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(k+j<i&&i-j-k<=n/2) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
					//cout<<i<<' '<<j<<' '<<k<<' '<<dp[i][j][k]<<'\n';
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
