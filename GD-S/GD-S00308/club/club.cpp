#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int fg=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') fg=-fg;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return fg*x;
}
int t,n,a[100001],b[100001],c[100001],f[101][101][101],ans;
bool cmp(int x,int y){
	return x>y;
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	while(t--){
		n=read();
		for(int i=1;i<=n;i++) a[i]=read(),b[i]=read(),c[i]=read();
		if(n<=200){
			ans=-1;
			memset(f,0,sizeof(f));
			f[1][0][0]=a[1];f[0][1][0]=b[1];f[0][0][1]=c[1];
			for(int i=1;i<=n;i++){
				for(int l=0;l<=min(i-1,n/2);l++){
					for(int k=0;k<=min(i-1,n/2);k++){
						int j=i-1-l-k;
						if(j<=n/2&&j>=0&&j<=i-1){
							if(l+1<=n/2) f[l+1][k][j]=max(f[l+1][k][j],f[l][k][j]+a[i]);
							if(k+1<=n/2) f[l][k+1][j]=max(f[l][k+1][j],f[l][k][j]+b[i]);
							if(j+1<=n/2) f[l][k][j+1]=max(f[l][k][j+1],f[l][k][j]+c[i]);
						}
					}
				}
			}
			for(int l=0;l<=n/2;l++){
				for(int k=0;k<=n/2;k++){
					int j=n-l-k;
					if(j<=n/2&&j>=0) ans=max(ans,f[l][k][j]);
				}
			}
			printf("%d\n",ans);
		}
		else {
			sort(a+1,a+1+n,cmp);
			ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}
