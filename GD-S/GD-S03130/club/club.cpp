#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+5;
const int M=201;
int f[M][M][M],ans;
int t,n;
int a[N][4];
int flag;
void init(){
	ans=0;flag=0;
	memset(f,0,sizeof(f));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		init();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0) flag=1;
		}
		if(flag==1){
			for(int i=1;i<=n;i++){
				int all=i-1;
				for(int r=0;r<=all;r++){
					for(int s=0;s<=all;s++){
						int t=all-s-r;
						if(t<0) break;
						if(r+1<=n/2){
							f[r+1][s][t]=max(f[r+1][s][t],f[r][s][t]+a[i][1]);
							ans=max(ans,f[r+1][s][t]);
						}
						if(s+1<=n/2){
							f[r][s+1][t]=max(f[r][s+1][t],f[r][s][t]+a[i][2]);
							ans=max(ans,f[r][s+1][t]);
						}
						if(t+1<=n/2){
							f[r][s][t+1]=max(f[r][s][t+1],f[r][s][t]+a[i][3]);
							ans=max(ans,f[r][s][t+1]);
						}
					}
				}
				
			}
			printf("%d\n",ans);	
		}
		else{
			int b[N];
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>=n/2+1;i--){
				ans+=b[i];
			}
			printf("%d\n",ans);
		}
	}
}
