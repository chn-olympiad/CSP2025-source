# include <bits/stdc++.h>
# define N 100010
using namespace std;
inline int read() {
	int w=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) w=(w<<1)+(w<<3)+(ch^48);
	return w*f;
}
int sss;
struct D {
	int a,b,c;
}G[N];
bool cmp(D x,D y) {
	return x.a+x.b+x.c>y.a+y.b+y.c;
}
bool Cmp(D x,D y) {
	return x.a+x.b>y.a+y.b;
}
bool CMp(D x,D y) {
	return x.a+x.c>y.a+y.c;
}
bool CMP(D x,D y) {
	return x.b+x.c>y.b+y.c;
}
bool cMp(D x,D y) {
	return x.a>y.a;
}
bool cMP(D x,D y) {
	return x.b>y.b;
}
bool CmP(D x,D y) {
	return x.c>y.c;
}
int T,n,ans,a[N][4],dp[N][4],cnt[N][4][4];
void js() {
	for(int i=1;i<=n;i++)
	    a[i][1]=G[i].a,a[i][2]=G[i].b,a[i][3]=G[i].c;
    memset(dp,0,sizeof(dp));
	  memset(cnt,0,sizeof(cnt));
	  for(int i=1;i<=n;i++) {
	    for(int j=1;j<=3;j++)
		  for(int l=1;l<=3;l++) {
		    if(cnt[i-1][l][j]<n/2) {
		      if(dp[i-1][l]+a[i][j]>dp[i][j]) {
		        dp[i][j]=max(dp[i][j],dp[i-1][l]+a[i][j]);
	            cnt[i][j][1]=cnt[i-1][l][1];
	            cnt[i][j][2]=cnt[i-1][l][2];
	            cnt[i][j][3]=cnt[i-1][l][3];
	            cnt[i][j][j]++;
			  }
			}      
		  }
	  }
	for(int i=1;i<=3;i++) 
	    ans=max(ans,dp[n][i]);
}
int f[105][105][105];
int f2[105][105][105];
int f3[105][105][105];
int f4[105][105][105];
void js2() {
	for(int j=0;j<=n/2;j++)
	  for(int l=0;l<=n/2;l++)
	    for(int r=0;r<=n/2;r++)
	      f[j][l][r]=-0x3f3f3f3f;
	f[0][0][0]=0;
    for(int i=1;i<=n;i++) {
      for(int j=0;j<=n/2;j++)
        for(int l=0;l<=n/2;l++)
          if(i-j-l-1>=0)
            f2[j][l][i-j-l-1]=f3[j][l][i-j-l-1]=f4[j][l][i-j-l-1]=f[j][l][i-j-l-1];
      for(int j=n/2;j>=1;j--)
        for(int l=n/2;l>=0;l--)
          if(i-j-l>=0)
            f2[j][l][i-j-l]=max(f2[j][l][i-j-l],f2[j-1][l][i-j-l]+a[i][1]),ans=max(ans,f2[j][l][i-j-l]);
      for(int l=n/2;l>=1;l--)
        for(int j=n/2;j>=0;j--)
          if(i-j-l>=0)
            f3[j][l][i-j-l]=max(f3[j][l][i-j-l],f3[j][l-1][i-j-l]+a[i][2]),ans=max(ans,f3[j][l][i-j-l]);
      for(int r=n/2;r>=1;r--)
        for(int j=n/2;j>=0;j--)
          if(i-j-r>=0)
            f4[j][i-j-r][r]=max(f4[j][i-j-r][r],f4[j][i-j-r][r-1]+a[i][3]),ans=max(ans,f4[j][i-j-r][r]);
      for(int j=0;j<=n/2;j++)
        for(int l=0;l<=n/2;l++)
          if(i-j-l>=0) {
            f[j][l][i-j-l]=max(max(f[j][l][i-j-l],f2[j][l][i-j-l]),max(f3[j][l][i-j-l],f4[j][l][i-j-l]));
            f2[j][l][i-j-l]=f3[j][l][i-j-l]=f4[j][l][i-j-l]=-0x3f3f3f3f;
		  }
	  for(int j=0;j<=n/2;j++)
        for(int l=0;l<=n/2;l++)
          if(i-j-l-1>=0)
            f2[j][l][i-j-l-1]=f3[j][l][i-j-l-1]=f4[j][l][i-j-l-1]=-0x3f3f3f3f;
	}
}
int s[4],sum;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--) {
	  n=read(),ans=0; 
	  if(n<=200) {
	    for(int i=1;i<=n;i++)
	      for(int j=1;j<=3;j++)
	        a[i][j]=read();
	    js2(),printf("%d\n",ans);
	    continue;
	  }
	  for(int i=1;i<=n;i++) 
	    G[i].a=read(),G[i].b=read(),G[i].c=read();
	  sort(G+1,G+1+n,cmp),js();
	  sort(G+1,G+1+n,Cmp),js();
	  sort(G+1,G+1+n,CMp),js();
	  sort(G+1,G+1+n,CMP),js();
	  sort(G+1,G+1+n,cMp),js();
	  sort(G+1,G+1+n,cMP),js();
	  sort(G+1,G+1+n,CmP),js();
	  printf("%d\n",ans);
    }
	return 0;
}
//3
//4
//4 2 1
//3 2 4
//5 3 4
//3 5 1
//4
//0 1 0
//0 1 0
//0 2 0
//0 2 0
//2
//10 9 8
//4 0 0

