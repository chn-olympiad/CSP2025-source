#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1e4;
int n;
int a[N][4],b[N],cnt;
void init(){
	scanf("%d",&n);
	for (int i=1;i<=n;++i){
		for (int j=1;j<=3;++j){
			scanf("%d",&a[i][j]);
		}
	} 
}
struct pai{
	int val,i,val1;
}z[N];
bool cmp(const pai x,const pai y){
	return x.val>y.val;
}
bool cmp1(const pai x,const pai y){
	if (x.val==y.val) return x.val1>y.val1;
	return x.val>y.val;
}
bool cmp2(const pai x,const pai y){
	if (x.val==y.val) return x.val1<y.val1;
	return x.val>y.val;
}
int p[N],ans;
void w(){
	for (int i=1;i<=n;++i){
		z[i].i=i;
		z[i].val=a[i][2]-a[i][1];
		z[i].val1=a[i][3]-a[i][2];
	}
	sort(z+1,z+1+n,cmp1);
	for (int i=1;i<=n/2;++i) p[z[i].i]=2;
	for (int i=1;i<=n;++i) if (p[i]==0) p[i]=1;
//	for (int i=1;i<=n;++i) printf("i=%d p=%d\n",i,p[i]);
	for (int i=1;i<=n;++i){
		z[i].i=i;
		z[i].val=a[i][3]-a[i][p[i]];
		z[i].val1=a[i][3-p[i]];
	}
	sort(z+1,z+1+n,cmp2);
	for (int i=1;i<=n/2;++i){
		if (z[i].val<0) break;
		p[z[i].i]=3;
	}
	cnt=0;
	for (int i=1;i<=n;++i) if (p[i]!=3) b[++cnt]=i;
	for (int i=1;i<=cnt;++i){
		p[b[i]]=1;
		z[i].i=i;
		z[i].val=a[b[i]][2]-a[b[i]][1];
	}
	sort(z+1,z+1+cnt,cmp);
	for (int i=1;i<=min(n/2,cnt);++i){
		if (z[i].val>0||(cnt-(i-1))>n/2){
			p[b[z[i].i]]=2;
		}
	}
	for (int i=1;i<=n;++i) ans+=a[i][p[i]];
//	for (int i=1;i<=n;++i) printf("i=%d p=%d\n",i,p[i]);
	printf("%d\n",ans);
}
void memsets(){
	ans=0;
	for (int i=1;i<=n;++i){
		p[i]=0;
	}
}
int f[40][40][40][40];
void work2(){
	for (int i=1;i<=n;++i){
		for (int j=n/2;j>=0;--j){
			for (int k=n/2;k>=0;--k){
				for (int l=n/2;l>=0;--l){
					if (j+k+l>n) continue;
					if (j-1>=0) f[i][j][k][l]=max(f[i-1][j-1][k][l]+a[i][1],f[i][j][k][l]);
					if (k-1>=0) f[i][j][k][l]=max(f[i-1][j][k-1][l]+a[i][2],f[i][j][k][l]);
					if (l-1>=0) f[i][j][k][l]=max(f[i-1][j][k][l-1]+a[i][3],f[i][j][k][l]);
					if (i==n&&j+k+l==n) ans=max(ans,f[i][j][k][l]);
				}
			}
		}
	}
	for (int i=1;i<=n;++i){
		for (int j=n/2;j>=0;--j){
			for (int k=n/2;k>=0;--k){
				for (int l=n/2;l>=0;--l){
					f[i][j][k][l]=0;
				}
			}
		}
	}
	printf("%d\n",ans);
	return ;
}
int tt;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&tt);
	while (tt--){
		init();
		if (n<=30) work2();
		else w();
		memsets();
	}
	return 0;
} 
