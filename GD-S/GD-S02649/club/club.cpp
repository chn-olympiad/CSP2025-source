#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,x[100010],y[100010],z[100010],ans;
int as[100010],bs[100010],cs[100010];
int dp[210][210][210],dp2[2][100010];
bool tp1=1,tp2=1;
struct t3{
	int x,y,z,lost;
}tt[100010];
int max3(int a,int b,int c){
	return max(max(a,b),c);
}
inline int choose_2(int a,int b,int c){
	if(a==2) return x[1]+x[2];
	if(b==2) return y[1]+y[2];
	if(c==2) return z[1]+z[2];
	if(a==1&&b==1) return max(x[1]+y[2],x[2]+y[1]);
	if(a==1&&c==1) return max(x[1]+z[2],x[2]+z[1]);
	if(c==1&&b==1) return max(z[1]+y[2],z[2]+y[1]);
	return 0;
}
//dfs(int t,int a,int b)表示前t个人，1号a个人，2号b个人，3号(t-a-b)个人
int dfs(int t,int a,int b){
	if(dp[t][a][b]!=0) return dp[t][a][b];
	if(t-a-b>n/2) return 0;
	if(a==0&&b==0) return dp[t][a][b]=cs[t];
	if(a==0&&t-a-b==0) return dp[t][a][b]=bs[t];
	if(b==0&&t-a-b==0) return dp[t][a][b]=as[t];
//	printf("t=%lld\ta=%lld\tb=%lld\tt-a-b=%lld\tn/2=%lld\n",t,a,b,t-a-b,n/2);
	if(t==2) return dp[t][a][b]=choose_2(a,b,t-a-b);
	int res=0;
	if(a>=1) res=max(res,dfs(t-1,a-1,b)+x[t]);
	if(b>=1) res=max(res,dfs(t-1,a,b-1)+y[t]);
	if(t-a-b>=1) res=max(res,dfs(t-1,a,b)+z[t]);
//	printf("returned %lld}\n",res);
	return dp[t][a][b]=res;
}
void TP2(){
	dp2[0][0]=y[1]+y[2],dp2[0][2]=x[1]+x[2];
	dp2[0][1]=max(x[1]+y[2],x[2]+y[1]);
	for(int i=3;i<=n;i++){
		dp2[1][0]=dp2[0][0]+y[i];
		for(int j=max(1ll,i-n/2);j<=min(i,n/2);j++){
			dp2[1][j]=dp2[0][j-1]+x[i];
			if(i-j<=n/2) dp2[1][j]=max(dp2[1][j],dp2[0][j]+y[i]);
		}
//		for(int j=max(1,i-n/2);j<=min(i,n/2);j++) printf("%lld ",dp2[1][j]);
//		printf("\n");
		for(int j=max(0ll,i-n/2);j<=min(i,n/2);j++) dp2[0][j]=dp2[1][j];
		for(int j=min(i,n/2)+1;j<=min(i,n/2)+3;j++) dp2[0][j]=0;
	}
	printf("%lld\n",dp2[0][n/2]);
}
bool cmp(const t3& a,const t3& b){
	return a.lost>b.lost;
}
void TP3(){
//	printf("tp3");
	sort(tt+1,tt+1+n,cmp);
	int cnt[4]={0,0,0,0},tmp,ttmp,pos;
	for(int i=1;i<=n;i++){
		tmp=INT_MIN;
		if(tt[i].x-tt[i].y-tt[i].z>tmp) tmp=tt[i].x-tt[i].y-tt[i].z,pos=1;
		if(tt[i].y-tt[i].x-tt[i].z>tmp) tmp=tt[i].y-tt[i].x-tt[i].z,pos=2;
		if(tt[i].z-tt[i].x-tt[i].y>tmp) tmp=tt[i].z-tt[i].x-tt[i].y,pos=3;
		if(cnt[pos]+1<=n/2){
			cnt[pos]++;
			if(pos==1) ans+=tt[i].x;
			if(pos==2) ans+=tt[i].y;
			if(pos==3) ans+=tt[i].z;
		}else{
			ttmp=INT_MIN;
			if(tt[i].x-tt[i].y-tt[i].z>ttmp&&tt[i].x-tt[i].y-tt[i].z!=tmp) ttmp=tt[i].x-tt[i].y-tt[i].z,pos=1;
			if(tt[i].y-tt[i].x-tt[i].z>ttmp&&tt[i].y-tt[i].x-tt[i].z!=tmp) ttmp=tt[i].y-tt[i].x-tt[i].z,pos=2;
			if(tt[i].z-tt[i].x-tt[i].y>ttmp&&tt[i].z-tt[i].x-tt[i].y!=tmp) ttmp=tt[i].z-tt[i].x-tt[i].y,pos=3;
			if(cnt[pos]+1<=n/2){
				cnt[pos]++;
				if(pos==1) ans+=tt[i].x;
				if(pos==2) ans+=tt[i].y;
				if(pos==3) ans+=tt[i].z;
			}else{
				if(tt[i].x-tt[i].y-tt[i].z!=ttmp&&tt[i].x-tt[i].y-tt[i].z!=tmp) pos=1;
				if(tt[i].y-tt[i].x-tt[i].z!=ttmp&&tt[i].y-tt[i].x-tt[i].z!=tmp) pos=2;
				if(tt[i].z-tt[i].x-tt[i].y!=ttmp&&tt[i].z-tt[i].x-tt[i].y!=tmp) pos=3;
				cnt[pos]++;
				if(pos==1) ans+=tt[i].x;
				if(pos==2) ans+=tt[i].y;
				if(pos==3) ans+=tt[i].z;
			}
		}
	}
	printf("%d\n",ans);
}
int read(){
	int x=1,f=0;
	char c=getchar();
	for(;c>'9'||c<'0';c=getchar()) if(c=='-') x=-1;
	for(;c>='0'&&c<='9';c=getchar()) f=(f<<3)+(f<<1)+(c-'0');
	return x*f; 
}
void solve(){
	ans=0;
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		x[i]=read(),y[i]=read(),z[i]=read();
//		scanf("%lld%lld%lld",&x[i],&y[i],&z[i]);
		if(y[i]!=0||z[i]!=0) tp1=0;
		if(z[i]!=0) tp2=0;
		as[i]=as[i-1]+x[i];
		bs[i]=bs[i-1]+y[i];
		cs[i]=cs[i-1]+z[i];
		tt[i].x=x[i],tt[i].y=y[i],tt[i].z=z[i];
		tt[i].lost=max3(x[i]-y[i]-z[i],y[i]-x[i]-z[i],z[i]-x[i]-y[i]);
	}
	if(tp1){
		sort(x+1,x+1+n);
		for(int i=n;i>n/2;i--) ans+=x[i];
		printf("%lld\n",ans);
		return;
	}
//	if(tp2){
//		fill(dp2[0],dp2[0]+1+n,0);
//		fill(dp2[1],dp2[1]+1+n,0);
//		TP2();
//		return;
//	}
	if(n>200){
		TP3();
		return;
	}
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			fill(dp[i][j],dp[i][j]+n+1,0);
	if(n==2){
		ans=max(ans,x[1]+y[2]);
		ans=max(ans,x[1]+z[2]);
		ans=max(ans,y[1]+x[2]);
		ans=max(ans,y[1]+z[2]);
		ans=max(ans,z[1]+x[2]);
		ans=max(ans,z[1]+y[2]);
		printf("%lld\n",ans);
		return;
	}
//	for(int i=0;i<=n;i++)
//		for(int j=0;j<=n;j++){
//			ans=max(ans,dfs(n,i,j));
//			printf("---------->i=%lld\tj=%lld\tdfs=%lld\n",i,j,dfs(n,i,j));
//		}

	for(int i=0;i<=n/2;i++)
		for(int j=n/2-i;j<=n/2;j++){
			ans=max(ans,dfs(n,i,j));
//			printf("---------->i=%lld\tj=%lld\tdfs=%lld\n",i,j,dfs(n,i,j));
		}
	printf("%lld\n",ans);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%lld",&T);
	while(T--) solve();
	return 0;
} 
