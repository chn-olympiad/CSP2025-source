#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
int t,n,maxx[100010][5],ans,a[100010][5];
int b[100010],cnt[5];
int dp[100][5][100];
struct node{
	int x1,x2,id;
}c[100010];
int flagA=1,flagB=1,flagC=1;
bool cmp(node x,node y){
	return abs(x.x1-x.x2)>abs(y.x1-y.x2);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				a[i][j]=read();
				if(a[i][3]!=0)flagA=0,flagB=0;
				if(a[i][2]!=0)flagA=0;
			}
			b[i]=a[i][1];
			c[i]=(node){a[i][1],a[i][2],0};
			if(a[i][1]<a[i][2])c[i]=(node){a[i][2],a[i][1],1};
		}
		if(flagA){
			sort(b+1,b+1+n);
			for(int i=1;i<=n/2;i++)ans+=b[i];
			cout<<ans;
			return 0;
		}
		if(flagB){
			sort(c+1,c+1+n,cmp);
			for(int i=1;i<=n;i++){
				if(cnt[(c[i].id==1?2:1)]>=n/2)cnt[(c[i].id==1?1:2)]++,ans+=c[i].x2;
				else ans+=c[i].x1,cnt[(c[i].id==1?2:1)]++;
			}
			cout<<ans;
			return 0;
		}
		memset(maxx,0,sizeof(maxx));
		memset(dp,0,sizeof(dp));
		dp[1][1][0]=max(a[1][2],a[1][3]);
		dp[1][2][0]=max(a[1][1],a[1][3]);
		dp[1][3][0]=max(a[1][1],a[1][2]);
		dp[1][1][1]=a[1][1];
		dp[1][2][1]=a[1][2];
		dp[1][3][1]=a[1][3];
		for(int i=2;i<=n;i++){
			int m=min(i,n/2);
			for(int j=m;j>=0;j--){
				for(int k=i-j;k>=0;k--){
					if(k>m||i-j-k>m)continue;
					if(j==0){
						dp[i][1][j]=dp[i-1][1][j];
						dp[i][2][j]=dp[i-1][2][j];
						dp[i][3][j]=dp[i-1][3][j];
					}
					dp[i][1][j]=max(dp[i-1][1][j-1],max(dp[i-1][2][k],dp[i-1][3][i-j-k]))+a[i][1];
					dp[i][2][j]=max(dp[i-1][2][j-1],max(dp[i-1][1][k],dp[i-1][3][i-j-k]))+a[i][2];
					dp[i][3][j]=max(dp[i-1][3][j-1],max(dp[i-1][2][k],dp[i-1][1][i-j-k]))+a[i][3];
				}
//				ans=max(ans,max(dp[i][1][j],max(dp[i][2][j],dp[i][3][j])));
//				dp[i][1][j]=max(dp[i-1][1][j-1],max(maxx[i-1][2],maxx[i-1][3]))+a[i][1];
//				dp[i][2][j]=max(dp[i-1][2][j-1],max(maxx[i-1][1],maxx[i-1][3]))+a[i][2];
//				dp[i][3][j]=max(dp[i-1][3][j-1],max(maxx[i-1][1],maxx[i-1][2]))+a[i][3];
			}
//			for(int j=1;j<=m;j++){
//				maxx[i][1]=max(maxx[i][1],dp[i][1][j]);
//				maxx[i][2]=max(maxx[i][2],dp[i][2][j]);
//				maxx[i][3]=max(maxx[i][3],dp[i][3][j]);
//			}
//			for(int j=1;j<=m;j++){
//				cout<<dp[i][1][j]<<" "<<dp[i][2][j]<<" "<<dp[i][3][j]<<endl;
//			}cout<<endl<<endl;
		}
//		cout<<dp[n][2][2]<<endl;
		for(int i=0;i<=n/2;i++){
			ans=max(ans,max(dp[n][1][i],max(dp[n][2][i],dp[n][3][i])));
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0

*/


